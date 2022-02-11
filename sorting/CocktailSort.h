//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_COCKTAILSORT_H
#define CPP_ALGORITHM_COCKTAILSORT_H

void CocktailSort(int a[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }

        swapped = false;

        --end;

        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

#endif //CPP_ALGORITHM_COCKTAILSORT_H
