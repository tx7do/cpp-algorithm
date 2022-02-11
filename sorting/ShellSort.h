//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_SHELLSORT_H
#define CPP_ALGORITHM_SHELLSORT_H

void ShellSort(int arr[], int n) {
    int j, i, gap;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i += 1) {
            int temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

#endif //CPP_ALGORITHM_SHELLSORT_H
