
#include <stdexcept>

template <typename T>
class Array {
private:
    T* array;
    unsigned int n;

public:
    Array() : array(nullptr), n(0) {}

    Array(unsigned int n) : array(new T[n]()), n(n) {}

    Array(const Array& other) : array(new T[other.n]), n(other.n) {
        for (unsigned int i = 0; i < n; ++i) {
            array[i] = other.array[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] array;
            array = new T[other.n];
            n = other.n;
            for (unsigned int i = 0; i < n; ++i) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    T& operator[](unsigned int index) {
        if (index >= n) {
            throw std::out_of_range("Array index out of bounds");
        }
        return array[index];
    }

    unsigned int size() const {
        return n;
    }

    ~Array() {
        delete[] array;
    }
};
