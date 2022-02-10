cmake_minimum_required(VERSION 3.16)
project(cpp-algorithm)

set(CMAKE_CXX_STANDARD 21)

add_executable(cpp-algorithm main.cpp sorting/CartesianTree.h sorting/SlowSort.h sorting/StoogeSort.h sorting/Util.h sorting/IntroSort.h sorting/InsertionSort.h sorting/HeapSort.h sorting/QuickSort.h sorting/MergeSort.h sorting/TimSort.h sorting/BucketSort.h sorting/BitonicSort.h sorting/SmoothSort.h sorting/StrandSort.h)
