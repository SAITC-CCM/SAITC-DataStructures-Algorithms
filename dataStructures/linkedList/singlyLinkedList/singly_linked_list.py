# Author: Dev Society.
# Creation Date: March 25, 2023.
# Description: A singly linked list using python.

# Node class for every element in the LinkedList
class Node:
    # -- Methods
    def __init__(self, data, next):
        # -- Atributes
        self.data = data
        self.next = next

    def print(self):
        print(self.data)

class SinglyLinkedList:
    # -- Methods
    def __init__(self):
        # -- Atributes
        self.size = 0
        self.head = None

    # Method that appends a value to the List's head.
    def add_first(self, data):
        if(self.head == None):
            self.head = Node(data, None)
        else:
            self.head = Node(data, self.head)
        
        self.size = self.size + 1

    # Method that appends a value to the List's tail.
    def add_last(self, data):
        if(self.head == None):
            self.head = Node(data, None)
        else:
            temp = self.head
            while(temp.next != None):
                temp = temp.next
            
            temp.next = Node(data, None)

        self.size = self.size + 1
    
    # Method that inserts a given value in a given position.
    def insert(self, data, index):
        if(index < 0 or index > self.size):
            raise 'Index out of bounds.'
        elif(index == 0):
            self.add_first(data)
        elif(index == self.size):
            self.add_last(data)
        else:
            temp = self.head
            for i in range(index - 1):
                temp = temp.next
            
            temp.next = Node(data, temp.next)
        
        self.size = self.size + 1
    
    # Method that removes the first element in the LinkedList.
    def remove_first(self):
        if(self.head == None):
            raise 'The list is empty.'
        else:
            return_value = self.head.data
            self.head = self.head.next
        
        self.size = self.size - 1
        return return_value

    # Method that removes the last element in the LinkedList.
    def remove_last(self):
        if(self.head == None):
            raise 'The list is empty.'
        else:
            if(self.size == 1):
                return_value = self.head.data
                self.head = None
            else:
                temp = self.head
                while(temp.next.next != None):
                    temp = temp.next
                
                return_value = temp.next.data
                temp.next = None
            
        self.size = self.size - 1
        return return_value
    
    # Method that reverses the list.
    def reverse(self):
        prev = None
        current = self.head
        next = None
        while(current != None):
            next = current.next
            current.next = prev
            prev = current
            current = next
        
        self.head = prev

    # Method that returs the element that is at any given index.
    def get_element(self, index):
        if(index < 0 or index >= self.size):
            raise 'Index out of bounds.'
        else:
            temp = self.head
            for i in range(index):
                temp = temp.next
            
            return temp.data

    # Method that prints each and every data atribute from the list's nodes.
    def print(self):
        self = self.head
        while(self != None):
            self.print()
            self = self.next