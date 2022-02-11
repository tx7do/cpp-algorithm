//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_COUNTINGSORT_H
#define CPP_ALGORITHM_COUNTINGSORT_H

#include <bits/stdc++.h>
#include <cstring>

#define RANGE 255

void CountingSort(char arr[]) {
    char output[strlen(arr)];

    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    for (i = 0; arr[i]; ++i) {
        ++count[arr[i]];
    }

    for (i = 1; i <= RANGE; ++i) {
        count[i] += count[i - 1];
    }

    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (i = 0; arr[i]; ++i) {
        arr[i] = output[i];
    }
}

#endif //CPP_ALGORITHM_COUNTINGSORT_H
