/*
 * CSC-301
 * project2.cpp
 * Spring 2025
 *
 * Partner 1: Joseph Barrows
 * Partner 2:
 * Date: March 5, 2025
 */

#include "project2.hpp"

using namespace std;

/*
 * Depth First Search
 */
vector<int> DFS(vector<Vertex> &adjList, Vertex &start, Vertex &exit)
{
    vector<int> path;

    // Create a stack and add the first vertex of the maze to the stack
    stack<Vertex> s;
    start.visited = true;
    s.push(start);

    // Repeat the process until the stack is empty
    while (!s.empty())
    {
        Vertex current = s.top();
        s.pop();

        // Look at each of the current vertex's neighbors
        // Add them to the stack if they are yet to be visisted
        for (int neighbor : current.neighbors)
        {
            if (adjList[neighbor].visited != true)
            {
                adjList[neighbor].visited = true;
                adjList[neighbor].previous = current.label;
                s.push(adjList[neighbor]);
            }
        }
    }

    // Back track through the path starting at the end vertex
    // Append these vertices to the path vector
    Vertex current = exit;
    while (current.previous != -1)
    {
        path.push_back(current.label);
        current = adjList[current.previous];
    }
    path.push_back(start.label);

    // Reverse the path so that it begins at the start vertex and return
    reverse(path.begin(), path.end());
    return path;
}

/*
 * Breadth First Search
 */
vector<int> BFS(vector<Vertex> &adjList, Vertex &start, Vertex &exit)
{
    vector<int> path;

    // Create a queue and add the first vertex to it
    queue<Vertex> q;
    start.visited = true;
    q.push(start);

    // Repeat the process until the queue is empty
    while (!q.empty())
    {
        Vertex current = q.front();
        q.pop();

        // Look at each of the current vertex's neighbors
        // Add them to the stack if they are yet to be visisted
        for (int neighbor : current.neighbors)
        {
            if (adjList[neighbor].visited != true)
            {
                adjList[neighbor].visited = true;
                adjList[neighbor].previous = current.label;
                q.push(adjList[neighbor]);
            }
        }
    }

    // Back track through the path starting at the end vertex
    // Append these vertices to the path vector
    Vertex current = exit;
    while (current.previous != -1)
    {
        path.push_back(current.label);
        current = adjList[current.previous];
    }
    path.push_back(start.label);

    // Reverse the path so that it begins at the start vertex and return
    reverse(path.begin(), path.end());
    return path;
}