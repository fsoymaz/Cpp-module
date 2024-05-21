#include <iostream>
#include "iter.hpp"

template <typename T>
void print(const T& value) {
    std::cout << value;
    if (std::is_same<T, float>::value) {
        std::cout << 'f';
    }
    std::cout << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, print<int>);

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(doubleArray, 5, print<double>);

    float floatArray[] = {1.2f, 2.2f, 3.4f, 4.4f};
    iter(floatArray, 4, print<float>);

    return 0;
}