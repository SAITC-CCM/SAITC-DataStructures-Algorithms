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

        // Methods that sorts the elements of the list using bubble sort algorithm.
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
};