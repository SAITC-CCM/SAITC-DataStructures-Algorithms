/**
 * @file merge.cpp
 * @brief Merge sort implementation
 * @date 2023-07-16
 *
 */

/**
 * @brief Merge two arrays into one
 *
 * @tparam T
 * @param arr the complete array
 * @param left the start of the left division
 * @param half the half of the array
 * @param right the end of the right division
 */
template <typename T>
void merge(T arr[], int left, int half, int right)
{
    const int LEFT_SIZE = half - left + 1,
              RIGHT_SIZE = right - half;
    int *leftArray = new int[LEFT_SIZE],
        *rightArray = new int[RIGHT_SIZE];

    // Copy data to temp arrays
    for (int i = 0; i < LEFT_SIZE; i++)
        leftArray[i] = arr[left + i];
    for (int i = 0; i < RIGHT_SIZE; i++)
        rightArray[i] = arr[half + 1 + i];

    // Start comparisons between left and right arrays
    int leftIndex, rightIndex, arrayIndex = left;
    leftIndex = rightIndex = 0;

    while (leftIndex < LEFT_SIZE && rightIndex < RIGHT_SIZE)
    {
        if (leftArray[leftIndex] <= rightArray[rightIndex])
        {
            arr[arrayIndex++] = leftArray[leftIndex++];
        }
        else
        {
            arr[arrayIndex++] = rightArray[rightIndex++];
        }
    }

    // Copy any remainding data
    while (leftIndex < LEFT_SIZE)
        arr[arrayIndex++] = leftArray[leftIndex++];
    while (rightIndex < RIGHT_SIZE)
        arr[arrayIndex++] = rightArray[rightIndex++];

    // Free memory
    delete[] leftArray;
    delete[] rightArray;
}

/**
 * @brief Merge sort implementation
 *
 * @tparam T
 * @param arr
 * @param left
 * @param right
 */
template <typename T>
void mergeSort(T arr[], int left, int right)
{
    if (left < right)
    {
        int half = left + (right - left) / 2;
        mergeSort(arr, left, half);
        mergeSort(arr, half + 1, right);
        merge(arr, left, half, right);
    }
}