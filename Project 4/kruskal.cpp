/*
 * CSC-301
 * kruskal.cpp
 * Spring 2025
 *
 * Partner 1: Joseph Barrows
 * Partner 2: Deven Platt
 * Date: 4/16/25
 */

#include "kruskal.hpp"

using namespace std;

/*
 * find : Finds the root vertex in a given set
 *
 * INPUTS
 * int v : An integer representing a vertex in the graph
 * vector<int> &pi : A list of integers representing each vertex's parent in their respective sets
 *
 * OUTPUTS
 * int pi[v] : v's set's root vertex
 */
int find(int v, vector<int> &pi)
{
    // Base case
    if (v == pi[v])
    {
        return v;
    }

    // Set each of v's parent nodes to the set's root node
    pi[v] = find(pi[v], pi);
    return pi[v];
}

/*
 * union_by_rank : Joins two disjoint sets
 *
 * INPUTS
 * int u, int v : Integers representing two vertices in the graph
 * vector<int> &rank : A list of all of the ranks of each vertex in the graph
 * vector<int> &pi : A list of parent nodes of each vertex in their respective sets
 *
 * OUTPUTS
 * None
 */
void union_by_rank(int u, int v, vector<int> &rank, vector<int> &pi)
{
    int rankV = rank[v];
    int rankU = rank[u];

    // Find the set roots of each vertex
    int rootV = find(v, pi);
    int rootU = find(u, pi);

    // Join the two sets by setting their set parents accordingly
    if (rankV == rankU)
    {
        pi[rootU] = rootV;
        rank[rootV]++;
    }
    else if (rankV > rankU)
    {
        pi[rootU] = rootV;
    }
    else
    {
        pi[rootV] = rootU;
    }

    return;
}

/*
 * kruskal : Generates a minimum spanning tree using Kruskal's algorithm
 *
 * INPUTS
 * vector<Vertex> &adjList : A list of all of the vertices in the graph
 * vector<Edge> &edgeList : A list of all the edges in the graph
 *
 * OUTPUTS
 * vector<Edge> mst : an array of edge objects that represent the generated minimum spanning tree
 */
vector<Edge> kruskal(vector<Vertex> &adjList, vector<Edge> &edgeList)
{
    // Initialize the empty MST.
    vector<Edge> mst;

    // For each vertex, we need rank values and pi pointers (ints) for the
    // Disjoint Sets. Initialize the rank to 0 and pi to be the vertex labels.
    int n = adjList.size();
    vector<int> rank(n, 0);
    vector<int> pi(n);
    // Create singleton sets of every vertex in the graph
    for (int i = 0; i < pi.size(); i++)
    {
        pi[i] = i;
    }

    // Iterate through every edge in the graph
    for (Edge e : edgeList)
    {
        // Find the nodes that the edge connects
        // And find their set root nodes
        int u = e.first.label;
        int v = e.second.label;

        int rootU = find(u, pi);
        int rootV = find(v, pi);

        // Link the two vertices in the MST if they are in disjoint sets
        // And union those two sets
        if (rootU != rootV)
        {
            union_by_rank(rootU, rootV, rank, pi);
            mst.push_back(e);
            adjList[v].mstNeighbors.push_back(u);
            adjList[u].mstNeighbors.push_back(v);
        }
    }

    return mst;
}