#include <string>
#include <iostream>

using namespace std;

void add_exclamation(string& str) {
    str.push_back('!');
}

void greetings(const string& name) {
    cout << "Good morning, " << name << "!\n";
}

int main() {
    string line("Hello, world");
    add_exclamation(line);
    cout << line << endl;

    greetings("Vitaly");

    return 0;
}
