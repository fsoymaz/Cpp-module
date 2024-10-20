#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input provided" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    for (int i = 1; i < argc; ++i) {
        try {
            int num = std::stoi(argv[i]);
            if (num <= 0) throw std::invalid_argument("Only positive integers are allowed");
            vec.push_back(num);
        } catch (...) {
            std::cerr << "Error: Invalid input" << std::endl;
            return 1;
        }
    }

    std::list<int> lst(vec.begin(), vec.end());

    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::clock_t start = std::clock();
    mergeInsertSort(vec);
    std::clock_t end = std::clock();
    double duration = 1000000.0 * (end - start) / CLOCKS_PER_SEC;

    std::cout << "After: ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << duration << " us" << std::endl;

    start = std::clock();
    mergeInsertSort(lst);
    end = std::clock();
    duration = 1000000.0 * (end - start) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: " << duration << " us" << std::endl;

    return 0;
}
