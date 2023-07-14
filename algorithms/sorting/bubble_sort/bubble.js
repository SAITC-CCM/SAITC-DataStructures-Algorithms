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
                [arr[j], arr[j+1]] = [arr[j+1], arr[j]]; // ES6 swap [a, b] = [b, a]
                swapped = true;
            }
        }
        if(!swapped) 
            break;
    }
    return arr;
}

console.log(bubbleSort([5, 4, 3, 2, 1]));
