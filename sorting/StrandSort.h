//
// Created by YLB on 2022/2/9.
//

#ifndef CLIONPROJ_STRANDSORT_H
#define CLIONPROJ_STRANDSORT_H

#include <list>

void StrandSort(int arr[], int const begin, int const end) {

    std::list<int> result;
    std::list<int> sorted;
    std::list<int> unsorted;

    for (int j = begin; j <= end; j++) {
        unsorted.push_back(arr[j]);
    }

    while (!unsorted.empty()) {
        sorted.push_back(unsorted.front());
        std::cout<< "f "<< unsorted.front() << std::endl;
        unsorted.pop_front();
        for (auto it = unsorted.begin(); it != unsorted.end();) {
            if (*it > sorted.back()) {
                std::cout<< *it << std::endl;
                sorted.push_back(*it);
                it = unsorted.erase(it);
            } else
                it++;
        }
        result.merge(sorted);
    }

    auto it = result.begin();
    for (int j = begin; j <= end; j++) {
        arr[j] = *it++;
    }
}

#endif //CLIONPROJ_STRANDSORT_H
