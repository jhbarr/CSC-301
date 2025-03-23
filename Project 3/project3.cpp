/*
 * CSC-301
 * project3.cpp
 * Spring 2025
 *
 * Partner 1: Joseph Barrows
 * Partner 2: David Rhoades
 * Date: 3/23/25
 */

#include "project3.hpp"

using namespace std;

/*
 * createAdjacencyMatrix: Creates an adjacency matrix for a graph representing the relationship between currency exchanges
 *
 * INPUTS
 * vector<double> &rates : an array representing the exchange rates between currencies
 * vector<string> &currencies : an array of currency names
 *
 * OUTPUTS
 * vector<double> adjMatrix : the graph adjacency matrix
 */
vector<double> createAdjacencyMatrix(vector<double> &rates,
                                     vector<string> &currencies)
{
    vector<double> adjMatrix(rates);

    // Iterate through the adjacency matrix and take the negative log of each value
    // So that the sum of an arbitrage cycle will be < 0
    for (int i = 0; i < rates.size(); i++)
    {
        double num = adjMatrix[i];
        adjMatrix[i] = -1 * log10(num);
    }

    return adjMatrix;
}

/*
 * detectArbitrage: Identifies a negative cost cycle within the currency graph. In this way, it detects arbitrage
 *
 * INPUTS
 * vector<double> &adjMatrix : an adjacency matrix for a graph representing the relationship between currency exchanges
 * vector<string> &currencies : an array of currency names
 * double tol : a number to assist in decimal comparisons
 *
 * OUTPUTS
 * vector<int> cycle : an array of currency names representing an arbitrage in the currency exchange.
 *      If the array is empty, an arbitrage does not exist
 *
 *
 */
vector<int> detectArbitrage(vector<double> &adjMatrix,
                            vector<string> &currencies,
                            double tol)
{

    // Get the number of vertices and initialize the dist and prev values.
    int n = currencies.size();
    vector<double> distances(n, numeric_limits<double>::infinity());
    vector<int> previous(n, -1);

    // Set the source vertex and its corresponding value
    distances[0] = 0;

    // Initialize the array to hold the cycle
    vector<int> cycle;
    int cycle_start = -1;

    // Iterate through the graph n times
    // Use the nth iteration to check if there is a negative cost cycle
    for (int i = 0; i < n; i++)
    {
        // Go through each currency (vertex) in the graph
        for (int row = 0; row < n; row++)
        {
            int current = row;
            double current_distance = distances[current];

            // Iterate through each of the current vertex's neighbors
            // Check if the distance to the neighbor can be updated to be a smaller value based on the current vertex's distance
            for (int value = 0; value < n; value++)
            {
                int neighbor = (row * n) + value;
                double neighbor_distance = distances[value];
                double edge_length = adjMatrix[neighbor];
                if (neighbor_distance > current_distance + edge_length + tol)
                {
                    distances[value] = current_distance + edge_length;
                    previous[value] = row;

                    // Check if an update was made on the nth iteration
                    if (i == n - 1)
                    {
                        cycle_start = value;
                    }
                }
            }
        }
    }

    // If an update was made on the nth iteration, backtrack through the created path to identify a cycle
    // Loop until the same currency appears twice (indicating a complete cycle)
    if (cycle_start != -1)
    {
        do
        {
            cycle.push_back(cycle_start);
            cycle_start = previous[cycle_start];
        } while (find(cycle.begin(), cycle.end(), cycle_start) == cycle.end());
        cycle.push_back(cycle_start);
    }

    // Reverse and return the cycle.
    reverse(cycle.begin(), cycle.end());
    return cycle;
}