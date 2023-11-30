// Author: Moisés Adame-Aguilar
// Creation Date: November 27, 2023.
// Description: A standard heap implemented only using a Doubly Linked List.

#ifndef __Heap
#define __Heap
#pragma once

#include"DoublyLinkedList.h"
#include<cmath>

using namespace std;
template<typename T>
class Heap {
    public:
        // -- Attributes
        DoublyLinkedList<T>* data;
        bool isMin;

        // -- Methods
        // Constructor method. 
        Heap(bool isMin = true){
            this->isMin = isMin;
            data = new DoublyLinkedList<T>();
        }

        // Method that inserts a value into the heap, preserving the right order.
        // Complexity: O(log n)
        void insert(T value) {
            data->addLast(value);
            restoreBackwards(data->size - 1);
        }

        // Method that deletes the highest value of 
        // the heap, preserving the right order.
        // Complexity: O(log n)
        void deletion() {
            if(data->size == 0){
                // If array dont have elements, throw error.
                throw -1;
            }else if(data->size == 1){
                // If array has one element only remove it.
                data->removeFirst();
            }else{
                // If array has more than one element, remove highest and restore.
                data->removeFirst();
                data->addFirst(data->removeLast());
                restoreForward(0);
            }
        }

        // Method that traverses and prints the heap's array.
        // Complexity: O(n)
        void print(){
            data->print();
        }

    private:
        // Method that restores the heap order for a given index
        // recursively when an insertion is performed.
        // Complexity: O(log n)
        void restoreBackwards(int index){
            // Obtain the index of the parent. p = ceil(i / 2) - 1
            int parentIndex = ceil(static_cast<float>(index) / static_cast<float>(2)) - 1;

            // If the parent is outside to the left of the Array, stop.
            if(parentIndex < 0){
                return ;
            }

            // Obtain the values of the parent and son.
            T value = data->get(index);
            T valueParent = data->get(parentIndex);

            // Swap the values of parent and son if order requieres it.
            // Check if the new parent is in the correct order.
            if((isMin && valueParent > value) || (!isMin && valueParent < value)){
                data->set(index, valueParent);
                data->set(parentIndex, value);
                restoreBackwards(parentIndex);
            }
        }

        // Method that restores the heap order for a given index
        // recursively when a deletion is performed.
        // Complexity: O(log n)
        void restoreForward(int index){
            // Obtain indexes for children left = 2i + 1, right = 2i + 2
            int leftIndex = 2 * index + 1;
            int rightIndex = 2 * index + 2;
            int lastIndex = data->size - 1;

            
            if(lastIndex < rightIndex && lastIndex < leftIndex){
                // If both children are outside array, stop.
                return ;
            }else if(lastIndex < rightIndex){
                // If just right child is outside array, 
                // check with left and swap if necessary.
                T valueParent = data->get(index);
                T valueLeft = data->get(leftIndex);

                if((isMin && valueParent > valueLeft) || (!isMin && valueParent < valueLeft)){
                    data->set(leftIndex, valueParent);
                    data->set(index, valueLeft);

                    restoreForward(leftIndex);
                }
            }else{
                // If both children are inside array, select smallest 
                // if isMin is true, and select biggest otherwise.
                T valueParent = data->get(index);
                T valueLeft = data->get(leftIndex);
                T valueRight = data->get(rightIndex);

                T valueSelected;
                int indexSelected;
                bool valueCoparison = valueLeft < valueRight;

                if(isMin){
                    valueSelected = valueCoparison ? valueLeft : valueRight;
                    indexSelected = valueCoparison ? leftIndex : rightIndex;
                }else{
                    valueSelected = valueCoparison ? valueRight : valueLeft;
                    indexSelected = valueCoparison ? rightIndex : leftIndex;
                }

                // Swap the values of parent and son if order requieres it.
                if((isMin && valueParent > valueSelected) || (!isMin && valueParent < valueSelected)){
                    data->set(index, valueSelected);
                    data->set(indexSelected, valueParent);

                    restoreForward(indexSelected);
                }
            }
        }
};

#endif