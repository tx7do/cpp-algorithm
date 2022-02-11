//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_ODDEVENSORT_H
#define CPP_ALGORITHM_ODDEVENSORT_H

#include<bits/stdc++.h>

void OddEvenSort(int arr[], int n) {
    bool isSorted = false;

    while (!isSorted) {
        isSorted = true;

        for (int i = 1; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }

        for (int i = 0; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
    }
}

#endif //CPP_ALGORITHM_ODDEVENSORT_H
