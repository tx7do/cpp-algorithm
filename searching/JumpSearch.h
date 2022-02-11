//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_JUMPSEARCH_H
#define CPP_ALGORITHM_JUMPSEARCH_H

#include <bits/stdc++.h>

template<typename T>
int JumpSearch(const std::vector<T> &vec, const T &target) {
    const int len = vec.size();
    int step = sqrt(len);

    int prev = 0;
    while (vec[std::min(step, len) - 1] < target) {
        prev = step;
        step += sqrt(len);
        if (prev >= len) {
            return -1;
        }
    }

    while (vec[prev] < target) {
        prev++;

        if (prev == std::min(step, len)) {
            return -1;
        }
    }

    if (vec[prev] == target) {
        return prev;
    }

    return -1;
}

#endif //CPP_ALGORITHM_JUMPSEARCH_H
