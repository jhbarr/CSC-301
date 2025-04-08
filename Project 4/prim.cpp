/*
 * CSC-301
 * prim.cpp
 * Spring 2025
 *
 * Partner 1: Joseph Barrows
 * Partner 2: Deven Platt
 * Date: 4/16/25
 */

#include "prim.hpp"

using namespace std;

/*
 * getMin
 */
int getMin(vector<double> &cost, vector<bool> &visited)
{
    return -1;
}

/*
 * isEmpty
 */
bool isEmpty(vector<bool> &visited)
{
    return true;
}

/*
 * prim : Generates a minimum spanning tree of a graph using Prim's algorithm
 *
 * INPUTS
 * vector<Vertex> &adjList : a list of vectors representing every vertex in the graph
 * vector<double> &adjMat : a matrix that describes the cost of travelling from one vertex to any other vertex
 *
 * OUTPUTS
 * vector<Edge> mst : an array of edge objects that represent the generated minimum spanning tree
 */
vector<Edge> prim(vector<Vertex> &adjList, vector<double> &adjMat)
{
    // Initialize the empty MST.
    vector<Edge> mst;

    // For each vertex, we need a visited flag, a 'cost' for Prim's, and the
    // prev values to track the MST. Store these in seperate vectors.
    int n = adjList.size();
    vector<bool> visited(n, false);
    vector<double> cost(n, numeric_limits<double>::infinity());
    vector<int> prev(n, -1);

    // Loop through |v| - 1 times
    // Since there will be |v| - 1 edges in the MST
    int current = 0;
    visited[current] = true;
    for (int i = 0; i < n - 1; i++)
    {
        // Iterate through each edge leaving current and update the cost vector accordingly
        for (int j = 0; j < n; j++)
        {
            // Check if the vertex is not the current vertex
            // (To eliminate zero cost problem)
            if (current != j)
            {
                // Update the cost vector if the current cost to get to the next vertex is less
                double edge_cost = adjMat[(current * n) + j];
                if (edge_cost < cost[j])
                {
                    cost[j] = edge_cost;

                    // Update the previous value as well
                    prev[j] = current;
                }
            }
        }

        // Iterate through the cost vector and select the next best edge
        // (Linear search)
        double min_cost = numeric_limits<double>::infinity();
        int min_cost_vertex;
        for (int j = 0; j < n; j++)
        {
            // If the cost to vertex j is less than the current mininmum cost
            // And j has yet to be visited
            // Then we want to set it as the next vertex to be visited
            if (cost[j] < min_cost && visited[j] == false)
            {
                min_cost = cost[j];
                min_cost_vertex = j;
            }
        }

        // Add the minimum edge to the MST
        Edge new_edge(adjList[min_cost_vertex], adjList[prev[min_cost_vertex]], min_cost);
        mst.push_back(new_edge);

        // Update MST neighbors
        adjList[min_cost_vertex].mstNeighbors.push_back(prev[min_cost_vertex]);
        adjList[prev[min_cost_vertex]].mstNeighbors.push_back(min_cost_vertex);

        // Mark the min_cost_vertex as visited and set it to current
        visited[min_cost_vertex] = true;
        current = min_cost_vertex;
    }

    return mst;
}