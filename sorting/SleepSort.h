//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_SLEEPSORT_H
#define CPP_ALGORITHM_SLEEPSORT_H

#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

// SleepSort
template<typename Iter, typename Compare = std::less<>>
void SleepSort(Iter first, Iter last, Compare cmp = Compare()) {
    if (first == last || first == last - 1) {
        return;
    }

    std::vector<std::thread> threads;

    for (auto it=first; it!=last; ++it) {
        threads.emplace_back([it]() {
            int arg = std::stoi(*it);
            std::this_thread::sleep_for(std::chrono::seconds(arg));
            std::cout << *it << std::endl;
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

#endif //CPP_ALGORITHM_SLEEPSORT_H
