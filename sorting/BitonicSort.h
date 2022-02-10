//
// Created by YLB on 2022/2/8.
//

#ifndef CLIONPROJ_BITONICSORT_H
#define CLIONPROJ_BITONICSORT_H

#include<bits/stdc++.h>

bool ASCENDING = true, DESCENDING = false;

void compAndSwap(int a[], int i, int j, bool dir) {
    if (dir == (a[i] > a[j])) {
        std::swap(a[i], a[j]);
    }
}

int powerOfTwo(int n) {
    return n >> 1;
}

int greatestPowerOfTwoLessThan(int n) {
    int k = 1;
    while (k < n) {
        k = k << 1;
    }
    return k >> 1;
}

void bitonicMerge(int a[], int low, int cnt, bool dir) {
    if (cnt < 2) {
        return;
    }

    int mid = greatestPowerOfTwoLessThan(cnt);

    for (int i = low; i < low + cnt - mid; ++i) {
        compAndSwap(a, i, i + mid, dir);
    }

    bitonicMerge(a, low, mid, dir);
    bitonicMerge(a, low + mid, cnt - mid, dir);
}

void bitonicSort(int a[], int low, int cnt, bool dir) {
    if (cnt < 2) {
        return;
    }

    int mid = powerOfTwo(cnt);

    bitonicSort(a, low, mid, !dir);
    bitonicSort(a, low + mid, cnt - mid, dir);

    bitonicMerge(a, low, cnt, dir);
}

void BitonicSort(int arr[], int const begin, int const end, const bool dir = true) {
    const int cnt = end - begin + 1;
    bitonicSort(arr, 0, cnt, dir);
}

#endif //CLIONPROJ_BITONICSORT_H
