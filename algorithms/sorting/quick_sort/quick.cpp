/**
 * @file quick.cpp
 * @brief A simple implementation of quick sort
 * @date 2023-07-20
 * 
 */
#include "../bubble_sort/bubble.cpp"

/**
 * @brief Partition the array
 * 
 * @tparam T 
 * @param arr 
 * @param left 
 * @param right 
 * @return int 
 */
template <typename T> int partition(T arr[], int left, int right)
{
    T pivot = arr[right];
    int temporalPivot = left - 1;

    for (int i = left; i < right; i++)
    {
        if (arr[i] < pivot)
        {
            temporalPivot++;
            swap(arr + temporalPivot, arr + i);
        }
    }

    swap(arr + temporalPivot + 1, arr + right);
    return temporalPivot + 1;
}

/**
 * @brief Quick sort implementation
 * 
 * @tparam T 
 * @param arr 
 * @param left 
 * @param right 
 */
template <typename T> void quick_sort(T arr[], int left, int right){
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }
}

#include <iostream>
int main(){
    int arr[] = {5, 4, 3, 2, 1};
    quick_sort(arr, 0, 4);
    for(int i = 0; i < 5; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}