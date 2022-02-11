//
// Created by YLB on 2022/2/10.
//

#ifndef CPP_ALGORITHM_COMBSORT_H
#define CPP_ALGORITHM_COMBSORT_H

#include<bits/stdc++.h>

int getNextGap(int gap) {
    gap = (gap * 10) / 13;

    if (gap < 1) {
        return 1;
    }
    return gap;
}

void CombSort(int a[], int n) {
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = getNextGap(gap);

        swapped = false;

        for (int i = 0; i < n - gap; i++) {
            if (a[i] > a[i + gap]) {
                std::swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}

#endif //CPP_ALGORITHM_COMBSORT_H
