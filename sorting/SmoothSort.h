//
// Created by YLB on 2022/2/9.
//

#ifndef CPP_ALGORITHM_SMOOTHSORT_H
#define CPP_ALGORITHM_SMOOTHSORT_H

#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <ctime>
#include "Util.h"

typedef uint32_t ui;
typedef uint64_t ull;

/**
 * The Leonardo numbers are similar to the Fibonacci numbers, and defined as :
 * L(0) = L(1) = 1
 * L(k + 2) = L(k + 1) + L(k) + 1
 */
class LeonardoNumber {
public:
    ui a;  // Actual number
    ui c;  // Companion number

public:
    LeonardoNumber() : a(1), c(1) {}

    LeonardoNumber(const LeonardoNumber &rhs) : a(rhs.a), c(rhs.c) {}

    // difference between actual number and companion number
    ui d() const { return a - c; }

    LeonardoNumber &operator++() {
        auto t = a;
        a = a + c + 1;
        c = t;
        return *this;
    }

    LeonardoNumber &operator--() {
        auto t = c;
        c = a - c - 1;
        a = t;
        return *this;
    }

    operator ui() const { return a; }
};

/**  Perform a "sift up" operation.  **/
template<typename Iter, typename Compare>
void sift(Iter first, ui root, LeonardoNumber l, Compare cmp) {
    ui r;
    while (l >= 3) {
        if (!cmp(*(first + root - l.d()), *(first + root - 1))) {
            r = root - l.d();
        } else {
            r = root - 1;
            --l;
        }
        if (!cmp(*(first + root), *(first + r))) {
            break;
        }
        std::iter_swap(first + root, first + r);
        root = r;
        --l;
    }
}

/**  Perform a "trinkle" operation.  **/
template<typename Iter, typename Compare>
void trinkle(Iter first, ui root, ull p, LeonardoNumber l, Compare cmp) {
    while (p) {
        for (; !(p % 2); p >>= 1) {
            ++l;
        }
        auto left = first + root;
        auto right = first + root - l;
        if (!--p || !cmp(*(left), *(right))) {
            break;
        }
        if (l == 1) {
            std::iter_swap(left, right);
            root -= l;
        } else if (l >= 3) {
            ui r1 = root - l.d(), r2 = root - l;
            if (!cmp(*(first + root - 1), *(first + r1))) {
                r1 = root - 1;
                p <<= 1;
                --l;
            }
            if (!cmp(*(first + r2), *(first + r1))) {
                std::iter_swap(first + root, first + r2);
                root = r2;
            } else {
                std::iter_swap(first + root, first + r1);
                root = r1;
                --l;
                break;
            }
        }
    }
    sift(first, root, l, cmp);
}

/**  Perform a "semi-trinkle" operation.  **/
template<typename Iter, typename Compare>
void semitrinkle(Iter first, ui root, ull p, LeonardoNumber l, Compare cmp) {
    if (!cmp(*(first + root - l.c), *(first + root))) {
        std::iter_swap(first + root - l.c, first + root);
        trinkle(first, root - l.c, p, l, cmp);
    }
}

// SmoothSort
template<typename Iter, typename Compare = std::less<>>
void SmoothSort(Iter first, Iter last, Compare cmp = Compare()) {
    if (first == last || first == last - 1) {
        return;
    }

    ull p = 1;
    LeonardoNumber l;
    ui len = last - first;

    ui i = 0;
    for (; ++i < len; ++p) {
        if (p % 8 == 3) {
            sift(first, i - 1, l, cmp);
            ++ ++l;
            p >>= 2;
        } else if (p % 4 == 1) {
            if (i + l.c < len) {
                sift(first, i - 1, l, cmp);
            } else {
                trinkle(first, i - 1, p, l, cmp);
            }
            for (p <<= 1; --l > 1; p <<= 1) {
            }
        }
    }

    trinkle(first, len - 1, p, l, cmp);

    for (--p; len-- > 1; --p) {
        if (l == 1) {
            for (; !(p % 2); p >>= 1) {
                ++l;
            }
        } else if (l >= 3) {
            if (p) {
                semitrinkle(first, len - l.d(), p, l, cmp);
            }
            --l, p <<= 1, ++p;
            semitrinkle(first, len - 1, p, l, cmp);
            --l, p <<= 1, ++p;
        }
    }
}

#endif //CPP_ALGORITHM_SMOOTHSORT_H
