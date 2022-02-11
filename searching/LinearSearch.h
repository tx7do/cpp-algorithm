//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_LINEARSEARCH_H
#define CPP_ALGORITHM_LINEARSEARCH_H

#include <bits/stdc++.h>

template<typename T>
int LinearSearch(const std::vector<T> &vec, const T &target) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (*it == target) {
            return *it;
        }
    }
    return -1;
}


#endif //CPP_ALGORITHM_LINEARSEARCH_H
