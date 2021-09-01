#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <tuple>
#include <cmath>

using namespace std;

// City record: [City name, latitude, longitude, population]
using Record = tuple<string, double, double, int>;
using RecordVec = vector<Record>;

double toRadians(double degree) {return degree * 0.0174533;}
constexpr double rEarth = 6371.;
// Haversine Formula
double dist(const Record& r1, const Record& r2) {
    double lat1 = toRadians(get<1>(r1));
    double lon1 = toRadians(get<2>(r1));
    double lat2 = toRadians(get<1>(r2));
    double lon2 = toRadians(get<2>(r2));
    return 2 * rEarth * asin(sqrt(0.5 * (1. - cos(lat2 - lat1)) +
        cos(lat1) * cos(lat2) * 0.5 * (1. - cos(lon2 - lon1))));
}

Record parse_record(const string& line) {
    double lat, lon;
    int population;
    istringstream ss(line);
    ss.ignore(1);
    string name;
    while (ss.peek() != '"') name.push_back(ss.get());
    ss.ignore(3);
    ss >> lat;
    ss.ignore(2);
    ss >> lon;
    ss.ignore(2);
    ss >> population;
    return {name, lat, lon, population};
}

RecordVec read_records(const string& fname, int min_pop = 0) {
    ifstream ifile(fname, ios::in);
    if (!ifile.good()) {
        cerr << "Can't load file " << fname << endl;
        return {};
    }

    RecordVec records;
    string line;
    while (getline(ifile, line)) {
        auto record = parse_record(line);
        if (get<3>(record) > min_pop) records.push_back(record);
    }

    cout << records.size() << " records read" << endl;
    return records;
}

bool operator!=(const Record& lhs, const Record& rhs) {
    const auto& [city1, lat1, lon1, pop1] = lhs;
    const auto& [city2, lat2, lon2, pop2] = rhs;
    return city1 != city2 || lat1 != lat2 || lon1 != lon2 || pop1 != pop2;
}

ostream& operator<<(ostream& os, const Record& record) {
    const auto& [city, lat, lon, pop] = record;
    return os << city << " (" << lat << ", " << lon << ") " << pop;
}

pair<Record, Record> find_closest(const RecordVec& cities) {
    double min_dist = 1.e9;
    Record r1, r2;
    for (const auto& ri : cities) {
        for (const auto& rj : cities) if (ri != rj) {
            double cur_dist = dist(ri, rj);
            if (cur_dist < min_dist) {
                r1 = ri;
                r2 = rj;
                min_dist = cur_dist;
            }
        }
    }
    return {r1, r2};
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Format: ./a.exe [ifname] [minpop]" << endl;
        return 0;
    }
    const string ifname = argv[1];
    const int min_pop = argc == 3 ? stoi(argv[2]) : 10000;

    auto cities = read_records(ifname, min_pop);
    auto [record1, record2] = find_closest(cities);
    cout << "Minimal distance " << dist(record1, record2) << " km is between\n"
         << " - " << record1 << " and\n"
         << " - " << record2 << endl;
    return 0;
}
