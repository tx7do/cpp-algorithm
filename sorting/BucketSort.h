//
// Created by YLB on 2022/2/7.
//

#ifndef CPP_ALGORITHM_BUCKETSORT_H
#define CPP_ALGORITHM_BUCKETSORT_H

#include <algorithm>
#include <iostream>
#include <vector>

void BucketSort(float arr[], int const begin, int const end) {
    const int length = end - begin + 1;

    std::vector<float> b[length];

    for (int i = begin; i <= end; i++) {
        int bi = int(float(length) * arr[i]);
        b[bi].push_back(arr[i]);
    }

    for (int i = begin; i <= end; i++) {
        sort(b[i].begin(), b[i].end());
    }

    int index = 0;
    for (int i = begin; i <= end; i++) {
        for (float j: b[i]) {
            arr[index++] = j;
        }
    }
}


#endif //CPP_ALGORITHM_BUCKETSORT_H
