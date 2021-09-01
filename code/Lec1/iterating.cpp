#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    for (int item : vec) cout << item << ' ';
    cout << endl;
    for (int& item : vec) ++item;
    for (size_t i = 0; i < vec.size(); ++i) cout << vec[i] << ' ';
    cout << endl;
    string s = "Novosibirsk";
    for (char ch : s) cout << ch << ' ';
    cout << endl;
}