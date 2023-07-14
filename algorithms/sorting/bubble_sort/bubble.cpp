
/**
 * @brief Bubble sort algorithm
 *
 * @tparam T
 */
template <typename T>
class BubbleSort
{
private:
    /**
     * @brief Swaps two elements
     *
     * @param first
     * @param second
     */
    void swap(T *first, T *second)
    {
        T temp = *first;
        *first = *second;
        *second = temp;
    }
public:
    /**
     * @brief Sorts the array using bubble sort algorithm
     *
     * @param arr
     * @param n
     */
    void sort(T arr[], int n)
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
};