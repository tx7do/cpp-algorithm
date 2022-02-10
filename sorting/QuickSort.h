//
// Created by YLB on 2022/2/7.
//

#ifndef CPP_ALGORITHM_QUICKSORT_H
#define CPP_ALGORITHM_QUICKSORT_H

#include <algorithm>

int partition(int arr[], int begin, int end) {
    int pivot = arr[end];
    int i = (begin - 1);

    for (int j = begin; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[end]);
    return i + 1;
}

void QuickSort(int arr[], int const begin, int const end) {
    if (begin < end) {
        int pi = partition(arr, begin, end);

        QuickSort(arr, begin, pi - 1);
        QuickSort(arr, pi + 1, end);
    }
}

#endif //CPP_ALGORITHM_QUICKSORT_H
