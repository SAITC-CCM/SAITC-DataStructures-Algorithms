/**
 * 
 * @param {Array} arr the array from which the elements will be swaped
 * @param {*} a the first position in the array
 * @param {*} b the second position in the array
 */
export const swap = (arr, a, b) => [arr[a], arr[b]] = [arr[b], arr[a]];

/** 
 * @brief A simple bubble sort algorithm
 * @param {Array} arr
 * @return {Array}
*/

function bubbleSort(arr) {
    var len = arr.length;
    var swapped;
    for(var i = 0; i < len; i++) {
        swapped = false;
        for(var j = 0; j < len - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
                swapped = true;
            }
        }
        if(!swapped) 
            break;
    }
}
export default bubbleSort;