/*
 * CSC-301
 * tsp.cpp
 * Spring 2025
 *
 * Partner 1: Joseph Barrows
 * Partner 2: Deven Platt
 * Date: 4/16/25
 */

#include "tsp.hpp"

using namespace std;

/*
 * tsp: Creates a tour that visits each node of the graph a single time reducing the cost of that tour
 *
 * INPUTS
 * vector<Vertex> &adjList : a list of vectors representing every vertex in the graph
 * Vertex &start : the first vertex in the graph used to start tracing the tour
 *
 * OUTPUTS
 * vector<int> tour : The TSP tour of the graph
 */
vector<int> tsp(vector<Vertex> &adjList, Vertex &start)
{
    // Create the empty tour.
    vector<int> tour;

    // Create the vector for tracking visited during the DFS.
    int n = adjList.size();
    vector<bool> visited(n, false);

    // Create a stack and push the start value onto it
    // Also mark the start value as visited so we don't accidentally end the tour preemptively
    stack<Vertex> s;
    s.push(start);
    visited[start.label] = true;

    while (!s.empty())
    {
        // Take the top node off of the stack
        Vertex current = s.top();
        s.pop();

        // Add the current vertex to the tour
        tour.push_back(current.label);

        // Iterate through the current vertex's neighbors
        // Only add the ones that have not been visited to the stack
        for (int neighbor : current.mstNeighbors)
        {
            if (visited[neighbor] == false)
            {
                // Add the neighbor to the stack and mark it as visited
                s.push(adjList[neighbor]);
                visited[neighbor] = true;
            }
        }
    }

    // Complete the tour by adding the starting vertex to the end
    tour.push_back(start.label);

    return tour;
}