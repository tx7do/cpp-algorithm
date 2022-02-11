//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_INTERPOLATIONSEARCH_H
#define CPP_ALGORITHM_INTERPOLATIONSEARCH_H

#include <bits/stdc++.h>

template<typename T>
int InterpolationSearch(const std::vector<T> &vec, const T &target) {
    return interpolationSearch(vec, 0, vec.size() - 1, target);
}

template<typename T>
int interpolationSearch(const std::vector<T> &vec, int left, int right, const T &target) {
    int pos;

    if (left <= right && target >= vec[left] && target <= vec[right]) {

        pos = left
              + (((double) (right - left) / (vec[right] - vec[left]))
                 * (target - vec[left]));

        if (vec[pos] == target) {
            return pos;
        }

        if (vec[pos] < target) {
            return interpolationSearch(vec, pos + 1, right, target);
        }

        if (vec[pos] > target) {
            return interpolationSearch(vec, left, pos - 1, target);
        }
    }
    return -1;
}

template<typename T>
int InterpolationSearch1(const std::vector<T> &vec, const T &target) {
    int lo = 0, hi = (vec.size() - 1);

    while (lo <= hi && target >= vec[lo] && target <= vec[hi]) {
        if (lo == hi) {
            if (vec[lo] == target) return lo;
            return -1;
        }
        int pos = lo + (((double) (hi - lo) /
                         (vec[hi] - vec[lo])) * (target - vec[lo]));

        if (vec[pos] == target) {
            return pos;
        }

        if (vec[pos] < target) {
            lo = pos + 1;
        } else {
            hi = pos - 1;
        }
    }
    return -1;
}


#endif //CPP_ALGORITHM_INTERPOLATIONSEARCH_H
