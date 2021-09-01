#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {1, 3, 5, 7, 9};
    for (int item : vec) cout << item << ' ';
    cout << '\n';
    cout << vec[3] << endl;  // 7
    cout << vec.size() << endl;  // 5
    vec[4] = 10;  // {1, 3, 5, 7, 10}
    vec.push_back(12);  // {1, 3, 5, 7, 10, 12}
    cout << vec.front() << ' ' << vec.back() << endl;  // 1 12
    vec.pop_back();  // {1, 3, 5, 7, 10}

    vector<int> vec2(10);  // size = 10
    vec2.resize(20);  // size = 20
    vector<int> vec3(2, 5);  // {2, 2, 2, 2, 2}
    vector<vector<int>> vec2d;
    vec2d.push_back(vec3);
    return 0;
}