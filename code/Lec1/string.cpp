#include <string>
#include <iostream>

using namespace std;

int main() {
    string a("Hello");
    string b("world");
    string c = a + ", " + b + "!";  // Hello, world!
    cout << c << endl;
    cout << c.size() << endl;  // 13
    string d = c.substr(7, 5);  // world
    size_t world_index = c.find("world"); // 7
    c.replace(world_index, 5, "Mike");  // Hello, Mike!
    int n = stoi("456");
    double x = stod("5.654");
    string pistr = "pi equals " + to_string(3.1415);
    cout << world_index << ' ' << c << ' ' << n << ' ' << x << ' ' << pistr << endl;
}
