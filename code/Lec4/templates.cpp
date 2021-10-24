#include <iostream>
// using namespace std;

// void swap(int& a, int& b) {
//     int c = b;
//     b = a;
//     a = c;
// }

// void swap(double& a, double& b) {
//     double c = b;
//     b = a;
//     a = c;
// }

template<typename T>
void swap(T& a, T& b) {
    T c = b;
    b = a;
    a = c;
}

template<int N, typename T>
T multiply(T val) {
    return N * val;
}


int main() {
    int a = 5;
    int b = 7;
    double c = 7.5;
    double d = 1.5;

    swap<int>(a, b);
    swap<double>(c, d);

    int e = multiply<6>(b);
    std::cout << e << std::endl;

    return 0; 
}
