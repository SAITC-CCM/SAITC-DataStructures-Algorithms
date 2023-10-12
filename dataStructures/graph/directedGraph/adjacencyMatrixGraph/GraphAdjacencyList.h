// Author: Moisés Adame-Aguilar
// Creation Date: October 11th, 2023.
// Description: A weighted, directed graph implemented with an adjacency matrix.

#ifndef __GraphAdjacencyMatrix
#define __GraphAdjacencyMatrix
#pragma once

#include<map>

using namespace std;

template <class T> 
class Graph {
    public:
        // Atributes
        int** adjacencyMatrix;
        int numNodes;
        T* indexesArray;
        int indexNode;

        // Constructor
        Graph(int numNodes){
            this->numNodes = numNodes;
            this->adjacencyMatrix = new int*[numNodes];
            this->indexesArray = new T[numNodes];
            indexNode = 0;
            
            for (int i = 0; i < numNodes; i++) {
                adjacencyMatrix[i] = new int[numNodes];
                for (int j = 0; j < numNodes; j++){
                    adjacencyMatrix[i][j] = 0;
                }
            }
        }

        // Method that prints the adjacencyMatrix of the graph.
        // Complexity: O(n²)
        void print(){
            for (int i = 0; i < numNodes; i++) {
                for (int j = 0; j < numNodes; j++){
                    cout << adjacencyMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        // Method that adds a node of type T to the Graph. If the number
        // of nodes has reached a limit, a message is showed.
        // Complexity: O(1)
        void addNode(T node){
            try {
                if(indexNode == numNodes){
                    throw -1;
                }else{
                    indexesArray[indexNode] = node;
                    indexNode++;
                }
            }catch (int error) {
                if(error == -1){
                    cout << "Nodes already full." << endl;
                }
            }
        }

        // Method that adds a weighted edge to the graph. If the node of origin
        // or the node of destination do are not found, a message is showed.
        // Complexity: O(n)
        void addEdge(T node, T adjacency, int weight){
            try {
                int indexNode = getIndex(node);
                int indexAdjacency = getIndex(adjacency);

                adjacencyMatrix[indexNode][indexAdjacency] = weight;
            }
            catch (int error) {
                if(error == -1){
                    cout << "Node not found" << endl;
                }
            }
        }
    
    private:

        // Method that finds the index of a given node ion the Graph
        // If the node is not found, a message is showed.
        // Complexity: O(n).
        int getIndex(T node){
            int index = -1;
            for(int i = 0; i < numNodes; i++){
                if(node == indexesArray[i]){
                    index = i;
                    break;
                }
            }

            if(index != -1){
                return index;
            }else{
                throw -1;
            }
        }


};

#endif