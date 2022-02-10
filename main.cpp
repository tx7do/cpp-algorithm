#include <iostream>

#include "sorting/Util.h"
#include "sorting/CartesianTreeSort.h"
#include "sorting/SlowSort.h"
#include "sorting/StoogeSort.h"
#include "sorting/HeapSort.h"
#include "sorting/MergeSort.h"
#include "sorting/QuickSort.h"
#include "sorting/InsertionSort.h"
#include "sorting/IntroSort.h"
#include "sorting/TimSort.h"
#include "sorting/BucketSort.h"
#include "sorting/BitonicSort.h"
#include "sorting/SmoothSort.h"
#include "sorting/StrandSort.h"

#define DO_SORT(FUNC, DATA) \
    int n = sizeof(DATA) / sizeof((DATA)[0]);\
    FUNC(DATA, 0, n - 1);\
    printf("sorted array: ");\
    printArray(DATA, 0, n - 1);

#define DO_SORT_ITER(FUNC, DATA) \
    FUNC(DATA.begin(), DATA.end());\
    printf("sorted array: ");\
    printArray(DATA.begin(), DATA.end());


void testStrandSort() {
//    {
//        int arr[] = {5, 6, 7, 2, 1, 0};
//        DO_SORT(StrandSort, arr)
//    }
    {
        int arr[] = {802, 630, 20, 745, 52, 300, 612, 932, 78, 187};
        DO_SORT(StrandSort, arr)
    }
}

void testSmoothSort() {
    {
        std::vector<int> arr = {2, 3, 6, 9, 0, 3, 9, 6, 5, 7};
        DO_SORT_ITER(SmoothSort, arr)
    }
    {
        std::vector<int> arr = {3, 2, 5, 1};
        DO_SORT_ITER(SmoothSort, arr)
    }
    {
        std::vector<int> arr = {3, 10, 2};
        DO_SORT_ITER(SmoothSort, arr)
    }
    {
        std::vector<int> arr = {3, 2};
        DO_SORT_ITER(SmoothSort, arr)
    }
}

void testBitonicSort() {
    {
        int arr[] = {55, 90, 74, 20, 16, 46, 43, 59, 2, 99, 79, 10, 73, 1, 68, 56, 3, 87, 40, 78, 14, 18, 51, 24, 57,
                     89, 4,
                     62, 53, 23, 93, 41, 95, 84, 88, 77};
        DO_SORT(BitonicSort, arr)
    }
    {
        int arr[] = {3, 7, 4, 8, 6, 2, 1, 5};
        DO_SORT(BitonicSort, arr)
    }
}

void testBucketSort() {
    {
        float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
        DO_SORT(BucketSort, arr)
    }
}


void testTimSort() {
    {
        int arr[] = {55, 90, 74, 20, 16, 46, 43, 59, 2, 99, 79, 10, 73, 1, 68, 56, 3, 87, 40, 78, 14, 18, 51, 24, 57,
                     89, 4,
                     62, 53, 23, 93, 41, 95, 84, 88};
        DO_SORT(TimSort, arr)
    }
}

void testMergeSort() {
    {
        int arr[] = {55, 90, 74, 20, 16, 46, 43, 59, 2, 99, 79, 10, 73, 1, 68, 56, 3, 87, 40, 78, 14, 18, 51, 24, 57,
                     89, 4,
                     62, 53, 23, 93, 41, 95, 84, 88};
        DO_SORT(MergeSort, arr)
    }
    {
        int arr[] = {6, 8, 9, 4, 12, 1};
        DO_SORT(MergeSort, arr)
    }
    {
        int arr[] = {2, 3, 1, 4};
        DO_SORT(MergeSort, arr)
    }
    {
        int arr[] = {12, 11, 13, 5, 6, 7};
        DO_SORT(MergeSort, arr)
    }
}

void testQuickSort() {
    {
        int arr[] = {6, 8, 9, 4, 12, 1};
        DO_SORT(QuickSort, arr)
    }
    {
        int arr[] = {2, 3, 1, 4};
        DO_SORT(QuickSort, arr)
    }
    {
        int arr[] = {12, 11, 13, 5, 6, 7};
        DO_SORT(QuickSort, arr)
    }
    {
        int arr[] = {-100, -99, -98, 0, 98, 99, 100, 0, 1, -100, 98};
        DO_SORT(QuickSort, arr)
    }
}

void testInsertionSort() {
    {
        int arr[] = {55, 90, 74, 20, 16, 46, 43, 59, 2, 99, 79, 10, 73, 1, 68, 56, 3, 87, 40, 78, 14, 18, 51, 24, 57,
                     89, 4,
                     62, 53, 23, 93, 41, 95, 84, 88};
        DO_SORT(InsertionSort, arr)
    }
    {
        int arr[] = {6, 8, 9, 4, 12, 1};
        DO_SORT(InsertionSort, arr)
    }
    {
        int arr[] = {2, 3, 1, 4};
        DO_SORT(InsertionSort, arr)
    }
    {
        int arr[] = {12, 11, 13, 5, 6, 7};
        DO_SORT(InsertionSort, arr)
    }
}

void testIntroSort() {
    {
        int arr[] = {55, 90, 74, 20, 16, 46, 43, 59, 2, 99, 79, 10, 73, 1, 68, 56, 3, 87, 40, 78, 14, 18, 51, 24, 57,
                     89, 4,
                     62, 53, 23, 93, 41, 95, 84, 88, 87};
        DO_SORT(IntroSort, arr)
    }
    {
        int arr[] = {6, 8, 9, 4, 12, 1};
        DO_SORT(IntroSort, arr)
    }
    {
        int arr[] = {2, 3, 1, 4};
        DO_SORT(IntroSort, arr)
    }
    {
        int arr[] = {12, 11, 13, 5, 6, 7};
        DO_SORT(IntroSort, arr)
    }
}

void testHeapSort() {
    {
        int arr[] = {55, 90, 74, 20, 16, 46, 43, 59, 2, 99, 79, 10, 73, 1, 68, 56, 3, 87, 40, 78, 14, 18, 51, 24, 57,
                     89, 4,
                     62, 53, 23, 93, 41, 95, 84, 88};
        DO_SORT(HeapSort, arr)
    }
    {
        int arr[] = {6, 8, 9, 4, 12, 1};
        DO_SORT(HeapSort, arr)
    }
    {
        int arr[] = {2, 3, 1, 4};
        DO_SORT(HeapSort, arr)
    }
    {
        int arr[] = {12, 11, 13, 5, 6, 7};
        DO_SORT(HeapSort, arr)
    }
}

void testSlowSort() {
    {
        int arr[] = {55, 90, 74, 20, 16, 46, 43, 59, 2, 99, 79, 10, 73, 1, 68, 56, 3, 87, 40, 78, 14, 18, 51, 24, 57,
                     89, 4,
                     62, 53, 23, 93, 41, 95, 84, 88};
        DO_SORT(SlowSort, arr)
    }
    {
        int arr[] = {6, 8, 9, 4, 12, 1};
        DO_SORT(SlowSort, arr)
    }
    {
        int arr[] = {2, 3, 1, 4};
        DO_SORT(SlowSort, arr)
    }
    {
        int arr[] = {12, 11, 13, 5, 6, 7};
        DO_SORT(SlowSort, arr)
    }
}

void testStoogeSort() {
    {
        int arr[] = {55, 90, 74, 20, 16, 46, 43, 59, 2, 99, 79, 10, 73, 1, 68, 56, 3, 87, 40, 78, 14, 18, 51, 24, 57,
                     89, 4,
                     62, 53, 23, 93, 41, 95, 84, 88};
        DO_SORT(StoogeSort, arr)
    }
    {
        int arr[] = {6, 8, 9, 4, 12, 1};
        DO_SORT(StoogeSort, arr)
    }
    {
        int arr[] = {2, 3, 1, 4};
        DO_SORT(StoogeSort, arr)
    }
    {
        int arr[] = {12, 11, 13, 5, 6, 7};
        DO_SORT(StoogeSort, arr)
    }
}

void testCartesianTreeSort() {
//    {
//        IntVector arr = {12, 11, 13, 5, 6, 7};
//        DO_SORT_ITER(CartesianTreeSort, arr)
//    }
    {
        IntVector arr = {55, 90, 74, 20, 16, 46, 43, 59, 2, 99, 79, 10, 73, 1, 68, 56, 3, 87, 40, 78, 14, 18, 51, 24, 57,
                         89, 4,
                         62, 53, 23, 93, 41, 95, 84, 88};
        DO_SORT_ITER(CartesianTreeSort, arr)
    }
}

void testCartesianTree() {
    {
//        IntVector arr = {1, 14, 5, 9, 8};
//        IntVector arr = {3, 2, 6, 1, 9};

        IntVector arr = {55, 90, 74, 20, 16, 46, 43, 59, 2, 99, 79, 10, 73, 1, 68, 56, 3, 87, 40, 78, 14, 18, 51, 24, 57,
                         89, 4,
                         62, 53, 23, 93, 41, 95, 84, 88};

        {
            CartesianTreeSort tree1;

            tree1.insertByLowestNodes(arr.begin(), arr.end());

            std::cout << "Inorder Traversal: ";
            IntVector inorder1;
            tree1.InorderTraversal(inorder1);
            printArray(inorder1.begin(), inorder1.end());
        }

        {
            CartesianTreeSort tree2;

            tree2.insertByRightMosts(arr.begin(), arr.end());

            std::cout << "Inorder Traversal: ";
            IntVector inorder2;
            tree2.InorderTraversal(inorder2);
            printArray(inorder2.begin(), inorder2.end());
        }
    }
}

void testPriorityQueue() {
    std::priority_queue<int, std::vector<int>, std::less<> > maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<> > minHeap;
    std::priority_queue<std::string, std::vector<std::string>, std::greater<>> strHeap;

    for (int i = 0; i < 5; i++)
    {
        maxHeap.push(i);
        minHeap.push(i);
    }

    strHeap.push("abc");
    strHeap.push("abcd");
    strHeap.push("cbd");

    while (!maxHeap.empty())
    {
        std::cout << maxHeap.top() << ' ';
        maxHeap.pop();
    }
    std::cout << std::endl;

    while (!minHeap.empty())
    {
        std::cout << minHeap.top() << ' ';
        minHeap.pop();
    }
    std::cout << std::endl;

    while (!strHeap.empty())
    {
        std::cout << strHeap.top() << ' ';
        strHeap.pop();
    }
    std::cout << std::endl;
}

int main() {
//    testCartesianTreeSort();
    testCartesianTree();
//    testSlowSort();
//    testStoogeSort();
//    testHeapSort();
//    testQuickSort();
//    testBucketSort();
//    testInsertionSort();
//    testIntroSort();
//    testTimSort();
//    testBitonicSort();
//    testSmoothSort();
//    testStrandSort();

//    testPriorityQueue();

    return 0;
}
