//
// Created by YLB on 2022/2/6.
//

#ifndef CPP_ALGORITHM_UTIL_H
#define CPP_ALGORITHM_UTIL_H

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int startPos, int endPos) {
    printf("[");
    for (int i = startPos; i <= endPos; ++i) {
        printf("%d", arr[i]);
        if (i != endPos) printf(" ");
    }
    printf("]\n");
}

void printArray(float arr[], int startPos, int endPos) {
    printf("[");
    for (int i = startPos; i <= endPos; ++i) {
        printf("%.4f", arr[i]);
        if (i != endPos) printf(" ");
    }
    printf("]\n");
}

template<typename Iter>
void printArray(Iter first, Iter last) {
    printf("[");
    for (auto it = first; it != last; ++it) {
        printf("%d", *it);
        if (it != last) printf(" ");
    }
    printf("]\n");
}


#endif //CPP_ALGORITHM_UTIL_H
