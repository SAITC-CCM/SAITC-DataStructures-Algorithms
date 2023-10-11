// Author: Dev Society.
// Creation Date: March 25, 2023.
// Description: A singly linked list using python.

#include <iostream>
using namespace std;

template<typename T>
class Node{
    public:
        // -- Attributes
        T data;
        Node<T>* next;
        
        // -- Methods
        // Constructor method. 
        Node(T data, Node<T>* next){
            this->data = data;
            this->next = next;
        }

        void print(){
            cout << this->data << endl;
        }
};

template<typename T>
class SinglyLinkedList{
    public:
        // -- Attributes
            Node<T>* head;
            int size;
        
        // -- Methods
        // Constructor method. 
        SinglyLinkedList(){
            this->head = NULL;
            this->size = 0;
        }

        // Method that appends a value to the List's head.
        void addFirst(T data){
            if(this->head == NULL){
                this->head = new Node<T>(data, NULL);
            }else{
                this->head = new Node<T>(data, this->head);
            }
            this->size++;
        }

        // Method that appends a value to the List's tail.
        void addLast(T data){
            if(this->head == NULL){
                this->head = new Node<T>(data, NULL);
            }else{
                Node<T>* temp = this->head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = new Node<T>(data, NULL);
            }
            this->size++;
        }

        // Method that inserts a given value in a given position.
        void insert(T data, int index){
            if(index < 0 || index > this->size){
                throw -1;
            }else if(index == 0){
                this->addFirst(data);
            }else if(index == this->size){
                this->addLast(data);
            }else{
                Node<T>* temp = this->head;
                for(int i = 0; i < index - 1; i++){
                    temp = temp->next;
                }

                temp->next = new Node<T>(data, temp->next);
            }
            this->size++;
        }

        // Method that removes the first element in the LinkedList.
        T removeFirst(){
            if(this->head == NULL){
                throw -1;
            }else{
                T returnValue;
                if(this->head->next != NULL){
                    Node<T>* temp;
                    temp = this->head->next;
                    returnValue = this->head->data;
                    delete(this->head);
                    this->head = temp;
                }else{
                    returnValue = this->head->data;
                    delete(this->head);
                    this->head = NULL;
                }
                this->size--;
                return returnValue;
            }
        }

        // Method that removes the last element in the LinkedList.
        T removeLast(){
            if(this->head == NULL){
                throw -1;
            }else{
                T returnValue;
                if(this->size == 1){
                    returnValue = this->head->data;
                    delete(this->head);
                    this->head = NULL;
                }else{
                    Node<T>* temp = this->head;
                    while(temp->next->next != NULL){
                        temp = temp->next;
                    }
                    returnValue = temp->next->data;
                    delete(temp->next);
                    temp->next = NULL;
                }
                this->size--;
                return returnValue;
            }
        }

        // Method that reverses the list.
        void reverse(){
            int initialSize = this->size;
            SinglyLinkedList<T>* reversedList = new SinglyLinkedList<T>();
            for(int i = 0; i < initialSize; i++){
                reversedList->addFirst(this->removeFirst());
            }
            this->head = reversedList->head;
            delete(reversedList);
        }

        // Method that returs the element that is at any given index.
        T getElement(int index){
            if(index < 0 || index >= this->size){
                throw -1;
            }else{
                Node<T>* temp = this->head;
                for(int i = 0; i < index; i++){
                    temp = temp->next;
                }
                return temp->data;
            }
        }

        // Method that prints each and every data atribute from the list's nodes.
        void print(){
            Node<T>* temp = this->head;
            while(temp != NULL){
                temp->print();
                temp = temp->next;
            }
        }

        // Method that sorts the elements of the list using bubble sort algorithm.
        // Complexity: O(n²)
        void bubbleSort(bool reverse){
            T tempData;
            for(int i = 0; i < size; i ++){
                Node<T>* aux = head;
                while(aux->next != NULL){
                    if(aux->data < aux->next->data && reverse){
                        tempData = aux->next->data;
                        aux->next->data = aux->data;
                        aux->data = tempData;
                    }else if(aux->data > aux->next->data && !reverse){
                        tempData = aux->next->data;
                        aux->next->data = aux->data;
                        aux->data = tempData;
                    }

                    aux = aux->next;
                }
            }
        }
        
        // Method that sorts the elements of the list calling Merge Sort algorithm.
        // Complexity: O(n log(n))
        void mergeSort(){
            this->head = this->mergeSort(0, this->size - 1);
        }

        // Method that sorts the elements of the list calling Quick Sort algorithm.
        // Complexity: O(n log(n))
        void quickSort(){
            this->head = this->quickSortPrivate();
        }

    private:
        // Method that sorts the elements of the list using Merge Sort algorithm.
        // Complexity: O(n log(n))
        Node<T>* mergeSort(int left, int right){
            if(left < right){
                // Find the half index.
                int half = (right + left) / 2;

                // Instantiate Left and Right Sublists
                SinglyLinkedList<T>* leftList = new SinglyLinkedList();
                SinglyLinkedList<T>* rightList = new SinglyLinkedList();

                // Instantiate an Auxiliare node to travers thorugh the lists.
                Node<T>* aux = head;
                bool correctOrder;

                // Divide the list into to sublists and sort them.
                for(int i = 0; i <= half; i++){
                    leftList->addLast(aux->data);
                    aux = aux->next;
                }

                for(int i = half + 1; i <= right; i++){
                    rightList->addLast(aux->data);
                    aux = aux->next;
                }
                
                leftList->head = leftList->mergeSort(0, leftList->size - 1);
                rightList->head = rightList->mergeSort(0, rightList->size - 1);

                // Merge the sublists into a new one.
                SinglyLinkedList<T>* mergeList = new SinglyLinkedList();
                Node<T>* auxLeft = leftList->head;
                Node<T>* auxRight = rightList->head;

                while(auxLeft != NULL && auxRight != NULL){
                    if(auxLeft->data < auxRight->data){
                        mergeList->addLast(auxLeft->data);
                        auxLeft = auxLeft->next;
                    }else{
                        mergeList->addLast(auxRight->data);
                        auxRight = auxRight->next;
                    }
                }

                if(auxLeft == NULL && auxRight == NULL){
                    return mergeList->head;

                }else if(auxLeft == NULL){
                    while(auxRight != NULL){
                        mergeList->addLast(auxRight->data);
                        auxRight = auxRight->next;
                    }
                    
                }else if(auxRight == NULL){
                    while(auxLeft != NULL){
                        mergeList->addLast(auxLeft->data);
                        auxLeft = auxLeft->next;
                    }
                }

                return mergeList->head;
            }else{
                return this->head;
            }
        }

        // Method that sorts the elements of the list using Quick Sort algorithm.
        // Complexity: O(n log(n))
        Node<T>* quickSortPrivate(){
            if(this->size > 1){
                // Obtaining the pivot and the aux.
                T pivot = this->head->data;
                Node<T>* aux = this->head->next;

                // Instantiate Left and Right Sublists
                SinglyLinkedList<T>* leftList = new SinglyLinkedList();
                SinglyLinkedList<T>* rightList = new SinglyLinkedList();

                // If value is smaller than pivot goes to leftList,
                // otherwise goes to rightList.
                while(aux != NULL){
                    if(aux->data < pivot){
                        leftList->addLast(aux->data);
                    }else{
                        rightList->addLast(aux->data);
                    }

                    aux = aux->next;
                }

                // Apply quickSort to leftList and rightList.
                leftList->head = leftList->quickSortPrivate();
                rightList->head = rightList->quickSortPrivate();

                // Merge leftList, the pivot and rightList.
                leftList->addLast(pivot);
                aux = leftList->head;
                while(aux->next != NULL){
                    aux = aux->next;
                }
                aux->next = rightList->head;

                return leftList->head;

            }else{
                return this->head;
            }
        }


};