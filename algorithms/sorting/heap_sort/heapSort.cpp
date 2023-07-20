/**
 * @file heapSort.cpp
 * @brief Simple implementation of the heap sort algorithm
 * @date 2023-07-20
 * 
 */

/*
   3
  / \
 1   4
[3, 1, 2] = [medium, left, right]
In powers of two, the medium is the parent of the left and right
*/

#include "../bubble_sort/bubble.cpp"

/**
 * @brief Heapify the array
 * 
 * @tparam T 
 * @param arr 
 * @param size 
 * @param node 
 */
template <typename T> void heapify(T arr[], int size, int node){
    // Establish the maximum value, the left branch and the right branch
    int max = node, left = 2 * node + 1, right = 2 * node + 2;

    // Check the actual maximum value
    if(left < size && arr[left] > arr[max])
        max = left;
    if(right < size && arr[right] > arr[max])
        max = right;

    // Swap elements if necessary
    if(max != node){
        swap(arr + node, arr + max);
        heapify(arr, size, max);
    }
}

/**
 * @brief Build the heap
 * 
 * @tparam T 
 * @param arr 
 * @param size 
 */
template <typename T> void buildHeap(T arr[], int size){
    for(int i = size/2 - 1; i >= 0; i--){
        heapify(arr, size, i);
    }
}

/**
 * @brief Heap sort implementation
 * 
 * @tparam T 
 * @param arr 
 * @param size 
 */
template <typename T> void heap_sort(T arr[], int size){
    buildHeap(arr, size);

    for(int i = size - 1; i >= 0; i--){
        swap(arr, arr + i);
        heapify(arr, i, 0);
    }
}