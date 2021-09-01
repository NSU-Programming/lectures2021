#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int sum = 0;
    const string fname("numbers.txt");
    ifstream ifile(fname, ios::in);
    if (!ifile.good()) {
        cout << "Can't load file " << fname << endl;
        return 0;
    }

    int value;
    while (ifile >> value) sum += value;

    cout << "Sum equals " << sum << endl;
    return 0;
}
