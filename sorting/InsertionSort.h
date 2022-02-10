//
// Created by YLB on 2022/2/7.
//

#ifndef CPP_ALGORITHM_INSERTIONSORT_H
#define CPP_ALGORITHM_INSERTIONSORT_H

#include <algorithm>

void InsertionSort(int arr[], int const begin, int const end) {
    int i, j;
    for (i = begin + 1; i <= end; ++i) {
        j = i;

        while (j > 0 && arr[j - 1] > arr[j]) {
            std::swap(arr[j - 1], arr[j]);
            --j;
            printf("[%d %d] [%d %d]\n", begin, end, i, j);
        }
    }
}

#endif //CPP_ALGORITHM_INSERTIONSORT_H
