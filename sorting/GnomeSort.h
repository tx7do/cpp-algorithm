//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_GNOMESORT_H
#define CPP_ALGORITHM_GNOMESORT_H

#include<bits/stdc++.h>

void GnomeSort(int arr[], int n) {
    int index = 0;

    while (index < n) {
        if (index == 0) {
            index++;
        }
        if (arr[index] >= arr[index - 1]) {
            ++index;
        } else {
            std::swap(arr[index], arr[index - 1]);
            --index;
        }
    }
}

#endif //CPP_ALGORITHM_GNOMESORT_H
