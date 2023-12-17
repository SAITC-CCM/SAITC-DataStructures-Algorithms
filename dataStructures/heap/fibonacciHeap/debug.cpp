#include "fibonacciHeap.h"

int main(){
    FibonacciHeap<int> heap;
    for(int i = 0; i < 10; i++){
        heap.insert(i);
    }

    heap.printHeap();

    for (int i = 0; i < 3; i++)
    {
        heap.extractMin();
        heap.printHeap();
    }
}