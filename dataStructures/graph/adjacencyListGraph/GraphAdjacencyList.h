// Author: Moisés Adame-Aguilar
// Fecha: October 10th, 2023
// Author: Graph using Adjacency Lists

#ifndef __GraphAdjacencyList
#define __GraphAdjacencyList
#pragma once

#include<map>
#include<vector>

using namespace std;

template <class T> 
class Graph {
    public:
        // Atributes
        map<T, vector<T> > adjacencyList;
        vector<T> nodeList;

        // Cosntructor
        Graph(){
            ; // Null statement
        }

        // Function for declaring all the nodes in the graph.
        // Complexity: O(1)
        void addNodes(T node){
            nodeList.push_back(node);
        }

        // Method that adds values into the adjacency list.
        // Complexity: O(1)
        void insert(T node, T adjacent){
            adjacencyList[node].push_back(adjacent);
        }

        // Method that prints each node of the 
        // graph and its respective adjacencies.
        // Complexity: O(n2)
        void print(){
            for (typename map<T, vector<T> >::iterator mapIterator = adjacencyList.begin(); mapIterator != adjacencyList.end(); mapIterator++){
                cout << mapIterator->first << " -> ";
                for (typename vector<T>::iterator vectorIterator = mapIterator->second.begin(); vectorIterator != mapIterator->second.end(); vectorIterator++){
                    cout << *vectorIterator << ", ";
                }
                cout << endl;
            }
        }

        // Function that calculates the page rank of a graph
        // for a given number of rounds.
        // Complexity: O(rounds * n2)
        void pageRank(int rounds) {
            map<T, double> rank;
            map<T, double> rankAuxiliar;
            int numberNodes = nodeList.size();

            // Initializing the rank list (making every node equally as possible)
            // and rankAuxiliar for the iterations as 0.
            for (typename vector<T>::iterator vectorIterator = nodeList.begin(); vectorIterator != nodeList.end(); vectorIterator++){
                rank[*vectorIterator] = 1.0 / numberNodes;
                rankAuxiliar[*vectorIterator] = 0.0;
            }

            // Iterate as many rounds as said updating both rank and rankAuxiliar.
            for(int iteration = 0; iteration < rounds; iteration++){
                for (typename map<T, vector<T> >::iterator mapIterator = adjacencyList.begin(); mapIterator != adjacencyList.end(); mapIterator++){
                    for (typename vector<T>::iterator vectorIterator = mapIterator->second.begin(); vectorIterator != mapIterator->second.end(); vectorIterator++){
                        rankAuxiliar[*vectorIterator] += rank[mapIterator->first] / adjacencyList[mapIterator->first].size();
                    }
                }

                rank = rankAuxiliar;

                for (typename vector<T>::iterator vectorIterator = nodeList.begin(); vectorIterator != nodeList.end(); vectorIterator++){
                    rankAuxiliar[*vectorIterator] = 0.0;
                }
            }

            for (typename map<T, double>::iterator rankIterator = rank.begin(); rankIterator != rank.end(); rankIterator++){
                cout << "R(" << rankIterator->first << ") = " << rankIterator->second << endl;
            }
        }
};

#endif