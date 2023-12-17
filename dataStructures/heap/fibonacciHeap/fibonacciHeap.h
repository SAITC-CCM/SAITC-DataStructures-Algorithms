/**
 * @file fibonacciHeap.h
 * @author Erno Mitrovic (ernesto.miranda@saitc.com)
 * @brief A Fibonacci heap is a data structure for priority queue operations,
 * consisting of a collection of heap-ordered trees. It has a better amortized
 * running time than many other priority queue data structures including the
 * binary heap and binomial heap.
 * @version 0.1
 * @date 2023-12-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FIBONACCI_HEAP_H
#define FIBONACCI_HEAP_H

// Fibonacci heap node
template <typename T>
struct FibonacciHeapNode
{
    T key;
    int degree;
    FibonacciHeapNode<T> *parent;
    FibonacciHeapNode<T> *child;
    FibonacciHeapNode<T> *left;
    FibonacciHeapNode<T> *right;
    bool marked;
};

#include <iostream>
#include <limits>
#include <vector>        // Optimized for managing memory in a dynamic way
#include <unordered_map> // Optimized for searching

template <typename T>
class FibonacciHeap
{
private:
    FibonacciHeapNode<T> *min;                             // The pointer to the min node
    int n;                                                 // Number of nodes in the heap
    std::unordered_map<T, FibonacciHeapNode<T> *> nodeMap; // Map to store the nodes

    void consolidate();
    void link(FibonacciHeapNode<T> *y, FibonacciHeapNode<T> *x);
    void cut(FibonacciHeapNode<T> *x, FibonacciHeapNode<T> *y);
    void cascadingCut(FibonacciHeapNode<T> *y);

public:
    FibonacciHeap();
    ~FibonacciHeap();

    void insert(T key);
    void remove(T key);
    void decreaseKey(T key, T newKey);
    T getMin();
    T extractMin();
    bool isEmpty();
    void printHeap();
};

#endif

/**
 * @brief Construct a new Fibonacci Heap<T>:: Fibonacci Heap object
 *
 * @tparam T
 */
template <typename T>
FibonacciHeap<T>::FibonacciHeap()
{
    min = nullptr;
    n = 0;
}

/**
 * @brief Destroy the Fibonacci Heap<T>:: Fibonacci Heap object
 *
 * @tparam T
 */
template <typename T>
FibonacciHeap<T>::~FibonacciHeap()
{
    while(!isEmpty()){
        extractMin();
    }
}

/**
 * @brief Insert a new node into the heap
 *
 * @tparam T
 * @param key
 */
template <typename T>
void FibonacciHeap<T>::insert(T key)
{
    FibonacciHeapNode<T> *node = new FibonacciHeapNode<T>;
    node->key = key;
    node->degree = 0;
    node->parent = nullptr;
    node->child = nullptr;
    node->left = node;
    node->right = node;
    node->marked = false;

    // Add the node to the map
    nodeMap[key] = node;

    // Merge the new node with the root list
    if (min != nullptr)
    {
        node->left = min;
        node->right = min->right;
        min->right = node;
        node->right->left = node;

        if (node->key < min->key)
        {
            min = node;
        }
    }
    else
    {
        min = node;
    }

    n++;
}

/**
 * @brief Remove a node from the heap
 *
 * @tparam T
 * @param key
 */
template <typename T>
void FibonacciHeap<T>::remove(T key)
{
    // Decrease the key to the minimum possible value
    decreaseKey(key, std::numeric_limits<T>::min());

    // Extract the node
    extractMin();
}

/**
 * @brief Decrease the key of a node
 *
 * @tparam T
 * @param key
 * @param newKey
 */
template <typename T>
void FibonacciHeap<T>::decreaseKey(T key, T newKey)
{
    // Get the node from the map
    FibonacciHeapNode<T> *node = nodeMap[key];

    // Check if the new key is greater than the current key
    if (newKey > node->key)
    {
        std::cout << "New key is greater than current key" << std::endl;
        return;
    }

    // Update the key
    node->key = newKey;

    // Update the parent
    FibonacciHeapNode<T> *parent = node->parent;
    if (parent != nullptr && node->key < parent->key)
    {
        cut(node, parent);
        cascadingCut(parent);
    }

    // Update the min
    if (node->key < min->key)
    {
        min = node;
    }
}

/**
 * @brief Get the minimum key
 *
 * @tparam T
 * @return T
 */
template <typename T>
T FibonacciHeap<T>::getMin()
{
    return min->key;
}

/**
 * @brief Extract the minimum key
 *
 * @tparam T
 * @return T
 */
template <typename T>
T FibonacciHeap<T>::extractMin()
{
    FibonacciHeapNode<T> *z = min;

    // Check if the heap is empty
    if (z == nullptr)
    {
        std::cout << "Heap is empty" << std::endl;
        return std::numeric_limits<T>::max();
    }

    // Add the children of z to the root list
    FibonacciHeapNode<T> *x = z->child;
    FibonacciHeapNode<T> *temp;
    int numChildren = z->degree;
    while (numChildren > 0)
    {
        temp = x->right;

        // Remove x from child list
        x->left->right = x->right;
        x->right->left = x->left;

        // Add x to root list
        x->left = min;
        x->right = min->right;
        min->right = x;
        x->right->left = x;

        // Set parent[x] to null
        x->parent = nullptr;
        x = temp;
        numChildren--;
    }

    // Remove z from root list
    z->left->right = z->right;
    z->right->left = z->left;

    if (z == z->right)
    {
        min = nullptr;
    }
    else
    {
        min = z->right;
        consolidate();
    }

    // Update the number of nodes
    n--;

    // Remove z from the map
    nodeMap.erase(z->key);

    // Get the key
    T key = z->key;

    // Delete z
    delete z;

    return key;
}

/**
 * @brief Check if the heap is empty
 *
 * @tparam T
 * @return true
 * @return false
 */
template <typename T>
bool FibonacciHeap<T>::isEmpty()
{
    return min == nullptr;
}

/**
 * @brief Print the heap
 *
 * @tparam T
 */
template <typename T>
void FibonacciHeap<T>::printHeap()
{
    if (min == nullptr)
    {
        std::cout << "Heap is empty" << std::endl;
        return;
    }

    std::cout << "The root list is: " << std::endl;
    FibonacciHeapNode<T> *temp = min;
    do
    {
        std::cout << temp->key << " ";
        temp = temp->right;
    } while (temp != min);
    std::cout << std::endl;
}

/**
 * @brief Consolidate the heap
 *
 * @tparam T
 */
template <typename T>
void FibonacciHeap<T>::consolidate()
{
    std::vector<FibonacciHeapNode<T> *> array(n, nullptr); // Vector initialized with nullptrs

    // Find the number of root nodes
    int rootNodes = 0;
    FibonacciHeapNode<T> *x = min;
    if (x != nullptr)
    {
        rootNodes++;
        x = x->right;
        while (x != min)
        {
            rootNodes++;
            x = x->right;
        }
    }

    // For each node in root list
    while (rootNodes > 0)
    {
        // Get degree of x
        int d = x->degree;
        FibonacciHeapNode<T> *next = x->right;

        // Merge nodes with the same degree
        while (array[d] != nullptr)
        {
            FibonacciHeapNode<T> *y = array[d];
            if (x->key > y->key)
            {
                std::swap(y, x);
            }
            link(y, x);
            array[d] = nullptr;
            d++;
        }
        array[d] = x;

        // Move forward
        x = next;
        rootNodes--;
    }

    // Update min
    min = nullptr;
    for (int i = 0; i < n; i++)
    {
        if (array[i] != nullptr)
        {
            if (min == nullptr)
            {
                min = array[i];
            }
            else
            {
                array[i]->left->right = array[i]->right;
                array[i]->right->left = array[i]->left;
                array[i]->left = min;
                array[i]->right = min->right;
                min->right = array[i];
                array[i]->right->left = array[i];

                if (array[i]->key < min->key)
                {
                    min = array[i];
                }
            }
        }
    }
}

/**
 * @brief Link two nodes
 *
 * @tparam T
 * @param y
 * @param x
 */
template <typename T>
void FibonacciHeap<T>::link(FibonacciHeapNode<T> *y, FibonacciHeapNode<T> *x)
{
    // Remove y from root list
    y->left->right = y->right;
    y->right->left = y->left;

    // Make y a child of x
    y->parent = x;

    if (x->child == nullptr)
    {
        x->child = y;
        y->right = y;
        y->left = y;
    }
    else
    {
        y->left = x->child;
        y->right = x->child->right;
        x->child->right = y;
        y->right->left = y;
    }

    // Increase degree[x]
    x->degree++;

    // Set mark[y] false
    y->marked = false;
}

/**
 * @brief Cut a node
 *
 * @tparam T
 * @param x
 * @param y
 */
template <typename T>
void FibonacciHeap<T>::cut(FibonacciHeapNode<T> *x, FibonacciHeapNode<T> *y)
{
    // Remove x from child list
    x->left->right = x->right;
    x->right->left = x->left;

    // Decrease degree[y]
    y->degree--;

    // Add x to root list
    x->left = min;
    x->right = min->right;
    min->right = x;
    x->right->left = x;

    // Set parent[x] to null
    x->parent = nullptr;

    // Set mark[x] to false
    x->marked = false;
}

/**
 * @brief Cascading cut
 *
 * @tparam T
 * @param y
 */
template <typename T>
void FibonacciHeap<T>::cascadingCut(FibonacciHeapNode<T> *y)
{
    FibonacciHeapNode<T> *z = y->parent;
    if (z != nullptr)
    {
        if (y->marked == false)
        {
            y->marked = true;
        }
        else
        {
            cut(y, z);
            cascadingCut(z);
        }
    }
}
