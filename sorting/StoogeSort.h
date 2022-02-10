//
// Created by YLB on 2022/2/6.
//

#ifndef CPP_ALGORITHM_STOOGESORT_H
#define CPP_ALGORITHM_STOOGESORT_H

#include <algorithm>

void StoogeSort(int arr[], int const begin, int const end) {
    if (begin >= end) {
        return;
    }

    if (arr[begin] > arr[end]) {
        std::swap(arr[begin], arr[end]);
    }

    if (end - begin + 1 > 2) {
        int t = (end - begin + 1) / 3;

        StoogeSort(arr, begin, end - t);
        StoogeSort(arr, begin + t, end);
        StoogeSort(arr, begin, end - t);
    }
}

#endif //CPP_ALGORITHM_STOOGESORT_H
