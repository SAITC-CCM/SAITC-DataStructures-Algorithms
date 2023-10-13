// Author: Moisés Adame-Aguilar
// Creation Date: October 13, 2023.
// Description: Implementation of a Stack, a Last In First Out (LIFO) DS.

#ifndef __Stack
#define __Stack
#pragma once

#include <iostream>
#include "../linkedList/doublyLinkedList/doublyLinkedList.h"
using namespace std;

template<typename T>
class Stack: public DoublyLinkedList<T> {
    public:
        // -- Methods
        // Constructor method. 
        Stack(): DoublyLinkedList<T>::DoublyLinkedList(){
            ; // Null statement
        }
        
        // Method that inserts an element to the stack.
        // Complexity: O(1)
        void push(T data){
            DoublyLinkedList<T>::addLast(data);
        }

        // Method that removes elements of the stack in the opposite order they entered.
        // Complexity: O(1)
        T pop(){
            return DoublyLinkedList<T>::removeLast();
        }

        // Method that returns the first element to enter the stack.
        // Complexity: O(1)
        T peek(){
            return DoublyLinkedList<T>::head->data;
        }
};

#endif