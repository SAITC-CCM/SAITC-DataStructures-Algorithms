
/**
 * @brief Bubble sort algorithm
 *
 * @tparam T
 */
/**
 * @brief Swaps two elements
 *
 * @param first
 * @param second
 */
template <typename T>
void swap(T *first, T *second)
{
    T temp = *first;
    *first = *second;
    *second = temp;
}
/**
 * @brief Sorts the array using bubble sort algorithm
 *
 * @param arr
 * @param n
 */
template <typename T>
void bubble_sort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}