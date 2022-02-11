//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_EXPONENTIALSEARCH_H
#define CPP_ALGORITHM_EXPONENTIALSEARCH_H

#include <bits/stdc++.h>
#include "BinarySearch.h"

template<typename T>
int ExponentialSearch(const std::vector<T> &vec, const T &target) {
    if (vec[0] == target) {
        return 0;
    }

    int i = 1;
    while (i < vec.size() && vec[i] <= target) {
        i = i * 2;
    }

    return BinarySearch(vec, i / 2,
                        std::min(i, vec.size() - 1), target);
}

#endif //CPP_ALGORITHM_EXPONENTIALSEARCH_H
