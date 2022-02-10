//
// Created by YLB on 2022/2/7.
//

#ifndef CLIONPROJ_INTROSORT_H
#define CLIONPROJ_INTROSORT_H

#include <algorithm>
#include <cmath>
#include "HeapSort.h"
#include "QuickSort.h"
#include "InsertionSort.h"

int *MedianOfThree(int *a, int *b, int *c) {
    if (*a < *b && *b < *c)
        return (int *) (b);

    if (*a < *c && *c <= *b)
        return (int *) (c);

    if (*b <= *a && *a < *c)
        return (int *) (a);

    if (*b < *c && *c <= *a)
        return (int *) (c);

    if (*c <= *a && *a < *b)
        return (int *) (a);

    if (*c <= *b && *b <= *a)
        return (int *) (b);

    return nullptr;
}

int *Partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;

            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (arr + i + 1);
}

void _IntroSort(int arr[], int *begin, int *end,
                int depthLimit) {
    long size = end - begin;

    if (size < 16) {
        InsertionSort(arr, *begin, *end);
        return;
    }

    if (depthLimit == 0) {
        HeapSort(arr, *begin, *end);
        return;
    }

    int *pivot = MedianOfThree(begin, begin + size / 2, end);

    std::swap(pivot, end);

    int *partitionPoint = Partition(arr, int(begin - arr), int(end - arr));
    _IntroSort(arr, begin, partitionPoint - 1, depthLimit - 1);
    _IntroSort(arr, partitionPoint + 1, end, depthLimit - 1);
}

void IntroSort(int arr[], int const begin, int const end) {
    int depthLimit = int(2 * std::log(end - begin));
    int left =begin;
    int right =end;
    _IntroSort(arr, &left, &right, depthLimit);
}

#endif //CLIONPROJ_INTROSORT_H
