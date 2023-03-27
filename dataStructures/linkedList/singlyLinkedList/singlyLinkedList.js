// Author: Dev Society.
// Creation Date: March 25, 2023.
// Description: A singly linked list using python.

// Node class for every element in the LinkedList
class Node{
    // -- Methods
    constructor(data, next){
        // -- Atributes
        this.data = data
        this.next = next
    }

    print(){
        console.log(this.data)
    }
}

// LinkedList class made up of many interlocked instances of Node
class singlyLinkedList{
    // -- Methods
    constructor(){
        // -- Atributes
        this.head = null
        this.size = 0
    }

    // Method that appends a value to the List's head.
    addFirst(data){
        if(this.head === null){
            this.head = new Node(data, null)
        }else{
            this.head = new Node(data, this.head)
        }
        this.size++
    }

    // Method that appends a value to the List's tail.
    addLast(data){
        if(this.head === null){
            this.head = new Node(data, null)
        }else{
            var temp = this.head
            while(temp.next !== null){
                temp = temp.next
            }
            
            temp.next = new Node(data, null)
        }
        this.size++
    }

    // Method that inserts a given value in a given position.
    insert(data, index){
        if(index < 0 || index > this.size){
            throw 'Index out of bounds.'
        }else if(index === 0){
            this.addFirst(data)
        }else if(index === this.size){
            this.addLast(data)
        }else{
            var temp = this.head
            for(var i = 0; i < index - 1; i++){
                temp = temp.next
            }

            temp.next = new Node(data, temp.next)
        }
        this.size++
    }

    // Method that removes the first element in the LinkedList.
    removeFirst(){
        var returnValue
        if(this.head === null){
            throw 'The list is empty.'
        }else{
            returnValue = this.head.data
            this.head = this.head.next
        }
        this.size--
        return returnValue
    }

    // Method that removes the last element in the LinkedList.
    removeLast(){
        var returnValue
        if(this.head === null){
            throw 'The list is empty.'
        }else{
            if(this.size === 1){
                returnValue = this.head.data
                this.head = null
            }else{
                var temp = this.head
                while(temp.next.next !== null){
                    temp = temp.next
                }
                returnValue = temp.next.data
                temp.next = null
            }
        }
        this.size--
        return returnValue
    }

    // Method that reverses the list.
    reverse(){
        var prev = null
        var current = this.head
        var next = null
        while(current != null) {
            next = current.next
            current.next = prev
            prev = current
            current = next
        }
        this.head = prev;
    }

    // Method that returs the element that is at any given index.
    getElement(index){
        if(index < 0 || index >= this.size){
            throw 'Index out of bounds.'
        }else{
            var temp = this.head
            for(var i = 0; i < index; i++){
                temp = temp.next
            }
            return temp.data
        }
    }

    // Method that prints each and every data atribute from the list's nodes.
    print(){
        var temp = this.head
        while(temp !== null){
            temp.print()
            temp = temp.next
        }
    }
}