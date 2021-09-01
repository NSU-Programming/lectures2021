#include <utility>
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

using Record = tuple<string, int, float>;

Record get_record() {
    const string name = "Vitaly";
    int age = 32;
    float score = 1.05;
    return {name, age, score};
}

int main() {
    double lat = 0.12;
    double lon = 0.24;
    auto point = make_pair(lat, lon);
    cout << "(" << point.first << ", "
         << point.second << ")" << endl;

    auto [name, age, score] = get_record();
    cout << name << ", " << age << ", " << score << endl;

    return 0;
}
