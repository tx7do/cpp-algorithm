//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_FIBONACCISEARCH_H
#define CPP_ALGORITHM_FIBONACCISEARCH_H

#include <bits/stdc++.h>

template<typename T>
int FibonacciSearch(const std::vector<T> &vec, const T &target) {
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < vec.size()) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = std::min(offset + fibMMm2, vec.size() - 1);

        if (vec[i] < target) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (vec[i] > target) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return i;
        }
    }

    if (fibMMm1 && vec[offset + 1] == target) {
        return offset + 1;
    }

    return -1;
}


#endif //CPP_ALGORITHM_FIBONACCISEARCH_H
