#include <iostream>

template<typename... Args>
auto sum(Args... args) {
    return (args * ...);
}

int main() {
    std::cout
        << sum(1, 2) << '\n'
        << sum(1, 2, 3) << '\n'
        << sum(1, 2, 3, 4) << '\n'
        << sum(1, 2, 3, 4, 5) << '\n';
    return 0;
}
