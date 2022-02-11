//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_BINARYSEARCH_H
#define CPP_ALGORITHM_BINARYSEARCH_H

#include <bits/stdc++.h>

template<typename T>
int BinarySearch(const std::vector<T> &vec, const T &target) {
    return binarySearch(vec, 0, vec.size() - 1, target);
}

template<typename T>
int binarySearch(const std::vector<T> &vec, int left, int right, const T &target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (vec[mid] == target) {
            return mid;
        }

        if (vec[mid] > target) {
            return binarySearch(vec, left, mid - 1, target);
        }

        return binarySearch(vec, mid + 1, right, target);
    }

    return -1;
}


#endif //CPP_ALGORITHM_BINARYSEARCH_H
