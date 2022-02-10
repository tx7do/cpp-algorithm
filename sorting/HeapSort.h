//
// Created by YLB on 2022/2/7.
//

#ifndef CPP_ALGORITHM_HEAPSORT_H
#define CPP_ALGORITHM_HEAPSORT_H

#include <algorithm>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int const begin, int const end) {
    for (int i = end / 2; i >= begin; i--) {
        heapify(arr, end+1, i);
    }

    for (int i = end; i > begin; i--) {
        std::swap(arr[begin], arr[i]);
        heapify(arr, i, begin);
    }
}


#endif //CPP_ALGORITHM_HEAPSORT_H
