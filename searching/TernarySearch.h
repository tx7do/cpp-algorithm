//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_TERNARYSEARCH_H
#define CPP_ALGORITHM_TERNARYSEARCH_H

#include <bits/stdc++.h>

template<typename T>
int TernarySearch(const std::vector<T> &vec, const T &target) {
    return ternarySearch(vec, 0, vec.size() - 1, target);
}

template<typename T>
int ternarySearch(const std::vector<T> &vec, int left, int right, const T &target) {
    if (right < left) {
        return -1;
    }

    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;

    if (vec[mid1] == target) {
        return mid1;
    }
    if (vec[mid2] == target) {
        return mid2;
    }

    if (target < vec[mid1]) {
        return ternarySearch(vec, left, mid1 - 1, target,);
    } else if (target > vec[mid2]) {
        return ternarySearch(vec, mid2 + 1, right, target);
    } else {
        return ternarySearch(vec, mid1 + 1, mid2 - 1, target);
    }
}

#endif //CPP_ALGORITHM_TERNARYSEARCH_H
