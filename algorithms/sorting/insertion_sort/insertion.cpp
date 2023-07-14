/**
 * @brief Quick implementation of insertion sort.
 * @tparam T Type of data to be sorted.
 * @param data Array of data to be sorted.
 * @param size Size of the array.
 */
template <typename T>
void insertion_sort(T *data, int size)
{
    // We assume that the first element is already sorted
    for (int i = 1; i < size; i++)
    {
        T key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

