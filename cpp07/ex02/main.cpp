#include <iostream>
#include "Array.hpp"

int main() {
    try {
        // Test default constructor
        Array<int> arr1;
        std::cout << "arr1 size: " << arr1.size() << std::endl;

        // Test constructor with size parameter
        Array<int> arr2(5);
        std::cout << "arr2 size: " << arr2.size() << std::endl;
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
        }

        // Test copy constructor
        Array<int> arr3(arr2);
        std::cout << "arr3 size: " << arr3.size() << std::endl;
        for (unsigned int i = 0; i < arr3.size(); ++i) {
            std::cout << "arr3[" << i << "] = " << arr3[i] << std::endl;
        }

        // Test assignment operator
        Array<int> arr4 = arr3;
        std::cout << "arr4 size: " << arr4.size() << std::endl;
        for (unsigned int i = 0; i < arr4.size(); ++i) {
            std::cout << "arr4[" << i << "] = " << arr4[i] << std::endl;
        }

        // Test modifying original and checking copy
        arr2[0] = 42;
        std::cout << "arr2[0] = " << arr2[0] << std::endl;
        std::cout << "arr3[0] = " << arr3[0] << std::endl; // Should remain unchanged

        // Test out-of-bounds access
        try {
            std::cout << arr2[10] << std::endl; // Should throw an exception
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
