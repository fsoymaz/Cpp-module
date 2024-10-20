#include "PmergeMe.hpp"
#include <algorithm>

// Merge function for vector
void merge(std::vector<int>& vec, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = vec[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = vec[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            ++i;
        } else {
            vec[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        vec[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        vec[k] = R[j];
        ++j;
        ++k;
    }
}

// Merge sort function for vector
void mergeSort(std::vector<int>& vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

// Merge-insert sort for vector
void mergeInsertSort(std::vector<int>& vec) {
    mergeSort(vec, 0, vec.size() - 1);
}

// Merge function for list
void merge(std::list<int>& lst, std::list<int>& left, std::list<int>& right) {
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator left_it = left.begin();
    std::list<int>::iterator right_it = right.begin();

    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it <= *right_it) {
            *it = *left_it;
            ++left_it;
        } else {
            *it = *right_it;
            ++right_it;
        }
        ++it;
    }

    while (left_it != left.end()) {
        *it = *left_it;
        ++left_it;
        ++it;
    }

    while (right_it != right.end()) {
        *it = *right_it;
        ++right_it;
        ++it;
    }
}

// Merge sort function for list
void mergeSort(std::list<int>& lst) {
    if (lst.size() <= 1) return;

    std::list<int> left, right;
    std::list<int>::iterator it = lst.begin();
    std::advance(it, lst.size() / 2);
    left.splice(left.begin(), lst, lst.begin(), it);
    right.splice(right.begin(), lst, lst.begin(), lst.end());

    mergeSort(left);
    mergeSort(right);
    merge(lst, left, right);
}

// Merge-insert sort for list
void mergeInsertSort(std::list<int>& lst) {
    mergeSort(lst);
}
