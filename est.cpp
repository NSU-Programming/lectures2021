#include <vector>
#include <string>

bool fcn(int a, int b) {
    if (a == b) {
        return false;
    } else {
        return true;
    }
}

bool fcn(int a, int b) {
    return !(a == b);
}



std::vector<std::string> vec = {"", "", ""};
std::vector<std::string> w;

// std::copy();
for (const std::string& s : vec) {
    w.push_back(s);
}
