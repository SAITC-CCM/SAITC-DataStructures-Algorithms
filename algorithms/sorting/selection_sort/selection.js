import swap from './../bubble_sort/bubble.js';

const select = (arr, i) => {
    let min = i;
    for (let j = i + 1; j < arr.length; j++) {
        if (arr[j] < arr[min]) min = j;
    }
    swap(arr, i, min);
}

const selectionSort = (arr) => {
    for (let i = 0; i < arr.length; i++) {
        select(arr, i);
    }
    return arr;
}