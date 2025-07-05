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

#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for std::pair
#include <limits>  // for std::numeric_limits

using namespace std;
/**
 * @brief Function to find the minimum spanning tree using Prim's algorithm
 * @param V Number of vertices in the graph
 * @param adj Adjacency list representation of the graph
 * @return The minimum cost of the spanning tree
 * @note The function uses a priority queue to efficiently get the minimum weight edge.
 * @note The graph is represented as an adjacency list where each entry contains pairs of (neighbor, weight).
 * @note The function assumes that the graph is connected and undirected.
 */
int primsMST(int V, vector<pair<int, int>> adj[])
{
    // Priority queue to select the edge with the minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Vector to track the minimum cost of edges
    vector<int> minCost(V, numeric_limits<int>::max());

    // Vector to track if a vertex is included in the MST
    vector<bool> inMST(V, false);

    // Start from the first vertex (0)
    pq.push({0, 0}); // {cost, vertex}
    minCost[0] = 0;

    int totalCost = 0;

    while (!pq.empty())
    {
        auto [cost, u] = pq.top();
        pq.pop();

        // If this vertex is already included in MST, skip it
        if (inMST[u])
            continue;

        // Include this vertex in MST
        inMST[u] = true;
        totalCost += cost;

        // Explore all adjacent vertices
        for (auto &[v, weight] : adj[u])
        {
            if (!inMST[v] && weight < minCost[v])
            {
                minCost[v] = weight;
                pq.push({weight, v});
            }
        }
    }

    return totalCost;
}

/**
 * @brief Main function to demonstrate the Prim's algorithm for MST
 */
int main()
{
    int V;
    cin >> V;
    vector<pair<int, int>> adj[V];
    int E;
    cin >> E;
    for (int i = 0; i < E; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight); // Since the graph is undirected
    }
    int totalCost = primsMST(V, adj);
    cout << "The minimum cost of the spanning tree is: " << totalCost << endl;
    return 0;
}