//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_SELECTIONSORT_H
#define CPP_ALGORITHM_SELECTIONSORT_H

#include<bits/stdc++.h>

void SelectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        std::swap(arr[min_idx], arr[i]);
    }
}


#endif //CPP_ALGORITHM_SELECTIONSORT_H
