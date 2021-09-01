#include <sstream>
#include <utility>  // std::pair
#include <iostream>
#include <cmath>

using namespace std;

/* Parses "(lat, lon)" string */
pair<double, double> parse(const string& data) {
    istringstream ss(data);
    double lat, lon;
    ss.ignore(1);  // skip '('
    ss >> lat;
    ss.ignore(2);  // skip ", "
    ss >> lon;
    cout << ss.str() << endl;
    return {lat, lon};
}

double toRadians(double degree) {return degree * 0.0174533;}
constexpr double rEarth = 6371.;
// Haversine Formula
double dist(double lat1, double long1, double lat2, double long2) {
    return 2 * rEarth * asin(sqrt(0.5 * (1 - cos(toRadians(lat2 - lat1))) +
        cos(toRadians(lat1)) * cos(toRadians(lat2)) *
            0.5 * (1 - cos(toRadians(long2 - long1)))
    ));
}

int main() {
    auto [lat1, lon1] = parse("(54.847830, 83.094392)");
    auto [lat2, lon2] = parse("(54.835815, 83.101360)");
    cout << dist(lat1, lon1, lat2, lon2) << " km" << endl;
}
