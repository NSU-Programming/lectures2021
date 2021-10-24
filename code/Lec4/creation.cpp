#include <iostream>
using namespace std;

class A {
 public:
    A() {std::cout << "A ctor\n";}
    ~A() {std::cout << "A dtor\n";}
};

class B : public A {
 public:
    B() {std::cout << "B ctor\n";}
    ~B() {std::cout << "B dtor\n";}
};

int main() {
    B b;
    return 0;
}
