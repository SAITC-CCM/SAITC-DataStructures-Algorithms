/**
 * @file mst.cpp
 * @brief An implementation of the algorithm to know the minimum spanning tree in a graph
 * @date 2023-07-20
 * There must be an undirected graph with weighted edges.
 * Remember that a graph without circles or loops is a tree.
 * A spanning tree of a graph is a subgraph that is a tree which connects all the vertices together,
 * so it ‘spans’ the original graph but using fewer edges.
 * 
 * Hence, let us use a greedy algorithm, which makes its decisions based only on what is best 
 * from the point of view of ‘local considerations’
 */

/*
* Prims algorithm:
* The algorithm starts with an empty spanning tree. The idea is to maintain two sets of vertices. 
* The first set contains the vertices already included in the MST, and the other set contains the vertices 
* not yet included. At every step, it considers all the edges that connect the two sets and picks
* the minimum weight edge from these edges. After picking the edge, it moves the other endpoint of 
* the edge to the set containing MST. 
** One of the most efficient approaches to have a MST is to use priority queues (STL in C++).
* Use additionally an array of vectors to represent the graph.
*/


