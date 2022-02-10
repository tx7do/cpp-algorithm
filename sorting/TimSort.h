//
// Created by YLB on 2022/2/7.
//

#ifndef CPP_ALGORITHM_TIMSORT_H
#define CPP_ALGORITHM_TIMSORT_H

#include "InsertionSort.h"
#include "MergeSort.h"
#include <algorithm>
#include "Util.h"

void TimSort(int arr[], int const begin, int const end) {

    const int RUN = 32;

    int left, mid, right;

    for (int i = begin; i < end; i += RUN) {
        left = i;
        right = std::min(i + RUN, end);
        InsertionSort(arr, left, right);

        printf("\n");
        printArray(arr, begin, end);
        printArray(arr, left, right);
        printf("\n");

//        printf("%d %d\n", left, right);
    }

    for (int size = RUN; size < end; size = 2 * size) {
        for (left = 0; left < end; left += 2 * size) {
            mid = left + size - 1;
            right = std::min((left + 2 * size - 1), (end - 1));

            if (mid < right) {
//                printArray(arr,begin, end);
//                printf("%d %d %d\n", left, mid, right);
                merge(arr, left, mid, right);
            }
        }
    }
}

#endif //CPP_ALGORITHM_TIMSORT_H
