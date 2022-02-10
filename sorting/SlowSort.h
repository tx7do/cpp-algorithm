//
// Created by YLB on 2022/2/6.
//

#ifndef CPP_ALGORITHM_SLOWSORT_H
#define CPP_ALGORITHM_SLOWSORT_H

#include <algorithm>

void SlowSort(int arr[], int const begin, int const end) {
    if (begin >= end) return;

    int m = (begin + end) / 2;

    SlowSort(arr, begin, m);
    SlowSort(arr, m + 1, end);

    if (arr[end] < arr[m]) {
        std::swap(arr[end], arr[m]);
    }

    SlowSort(arr, begin, end - 1);
}

#endif //CPP_ALGORITHM_SLOWSORT_H
