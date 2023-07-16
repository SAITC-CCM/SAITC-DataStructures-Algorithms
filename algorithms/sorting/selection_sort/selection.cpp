/**
 * @file selection.cpp
 * @brief Algorithm for the selection sort separated in two functions.
 */

// Using the swap function from the bubble sort
#include "..\bubble_sort\bubble.cpp"

/**
 * @brief Select the minimum element from the array and swap it with the element from i.
 *
 * @tparam T
 * @param arr
 * @param i
 * @param N
 */
template <typename T>
void select(T arr[], int i, const int N)
{
    int min = i;
    for (int j = i + 1; j < N; j++)
    {
        if (arr[j] < arr[min])
        {
            min = j;
        }
    }
    if (min != i)
    {
        swap(arr + i, arr + min);
    }
}

/**
 * @brief Selection sort algorithm
 *
 * @tparam T
 * @param arr
 * @param N
 */

template <typename T>
void selection_sort(T arr[], const int N)
{
    for (int i = 0; i < N; i++)
    {
        select(arr, i, N);
    }
}