/*
 * CSC-301
 * project2.cpp
 * Spring 2025
 *
 * Partner 1:
 * Partner 2:
 * Date:
 */

#include "project2.hpp"

using namespace std;

/*
 * Depth First Search
 */
vector<int> DFS(vector<Vertex> &adjList, Vertex &start, Vertex &exit)
{
    vector<int> path;
    stack<Vertex> s;

    start.visited = true;
    s.push(start);

    while (!s.empty())
    {
        Vertex current = s.top();
        s.pop();

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

    Vertex current = exit;
    while (current.previous != -1)
    {
        path.push_back(current.label);
        current = adjList[current.previous];
    }
    path.push_back(start.label);

    reverse(path.begin(), path.end());
    return path;
}

/*
 * Breadth First Search
 */
vector<int> BFS(vector<Vertex> &adjList, Vertex &start, Vertex &exit)
{
    vector<int> path;
    queue<Vertex> s;

    start.visited = true;
    s.push(start);

    while (!s.empty())
    {
        Vertex current = s.front();
        s.pop();

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

    Vertex current = exit;
    while (current.previous != -1)
    {
        path.push_back(current.label);
        current = adjList[current.previous];
    }
    path.push_back(start.label);

    reverse(path.begin(), path.end());
    return path;
}