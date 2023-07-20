/**
 * @file count.cpp
 * @brief Simple implementation of a counting sort algorithm, works only with integers or chars
 * @date 2023-07-20
 * 
 */

/**
 * @brief Finds the maximum value in an array
 * 
 * @param arr 
 * @return int 
 */
int max(int *arr){
    int max = arr[0];
    for(int i = 1; i < sizeof(arr); i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

/**
 * @brief Sorts an array using the counting sort algorithm
 * 
 * @param arr 
 * @param size 
 */
void counting_sort(int *arr, int size){
    int max_value = max(arr);
    int *count = new int[max_value + 1];
    for(int i = 0; i < max_value + 1; i++){
        count[i] = 0;
    }
    for(int i = 0; i < size; i++){
        count[arr[i]]++;
    }
    int j = 0;
    for(int i = 0; i < max_value + 1; i++){
        while(count[i] > 0){
            arr[j] = i;
            j++;
            count[i]--;
        }
    }
    delete[] count;
}
