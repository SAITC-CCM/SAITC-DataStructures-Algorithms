// Author: Moisés Adame-Aguilar
// Creation Date: October 12, 2023.
// Description: Implementation of a Standard Queue, a First In First Out (FIFO) DS.

#ifndef __StandardQueue
#define __StandardQueue
#pragma once

#include <iostream>
#include "../../linkedList/doublyLinkedList/doublyLinkedList.h"
using namespace std;

template<typename T>
class StandardQueue: public DoublyLinkedList<T> {
    public:
        // -- Methods
        // Constructor method. 
        StandardQueue(): DoublyLinkedList<T>::DoublyLinkedList(){
            ; // Null statement
        }
        
        // Method that inserts an element to the queue.
        // Complexity: O(1)
        void enqueue(T data){
            DoublyLinkedList<T>::addLast(data);
        }

        // Method that removes elements of the queue in the order they entered.
        // Complexity: O(1)
        T dequeue(){
            return DoublyLinkedList<T>::removeFirst();
        }

        // Method that returns the first element to enter the queue.
        // Complexity: O(1)
        T peek(){
            return DoublyLinkedList<T>::head->data;
        }
};

#endif