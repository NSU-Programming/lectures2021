#include <functional>
#include <iostream>

int apply_to(int val, std::function<int(int)> cb) {
    return cb(val);
}

int main() {
    int n = 100;
    int w = apply_to(n, [](int a) {return a * a;});
    std::cout << w << std::endl;
    return 0;
}
