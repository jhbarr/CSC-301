/*
 * CSC-301
 * project2.hpp
 * Spring 2025
 *
 * Partner 1:
 * Partner 2:
 * Date:
 */

#ifndef PROJECT2_HPP_
#define PROJECT2_HPP_

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include "Vertex.hpp"

std::vector<int> DFS(std::vector<Vertex> &adjList, Vertex &start, Vertex &exit);
std::vector<int> BFS(std::vector<Vertex> &adjList, Vertex &start, Vertex &exit);

#endif  // PROJECT2_HPP_