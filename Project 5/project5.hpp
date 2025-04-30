/*
 * CSC-301
 * project5.hpp
 * Spring 2025
 *
 * Partner 1:
 * Partner 2:
 * Date:
 */

#ifndef PROJECT5_HPP_
#define PROJECT5_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include "Edit.hpp"

/*
 * EDkernel - fill the (i,j) entry of the table.
 */
void EDkernel(std::string &src, std::string &dest, bool useASM, int numCols,
              std::vector<int> &table, int i, int j);

/*
 * EDhusk - create and iteratively fill the table in the correct order.
 */
std::vector<int> EDhusk(std::string &src, std::string &dest, bool useASM);

/*
 * getNumEdits - given a filled table, return the min number of edits.
 */
int getNumEdits(std::string &src, std::string &dest, std::vector<int> &table);

/*
 * getEdits - reconstruct the optimal edits given a filled table.
 */
std::vector<Edit> getEdits(std::string &src, std::string &dest, 
                           std::vector<int> &table);

/*
 * printTable: prints the table so it looks nice.
 *
 * INPUTS
 * string src: the source string for ED (or ASM).
 * string dest: the destination string for ED (or ASM).
 * vector<int> &table: the table itself.
 *
 * OUTPUTS
 * string tableString.str(): the pretty string.
 */
std::string printTable(std::string &src, std::string &dest, 
                       std::vector<int> &table);

#endif  // PROJECT5_HPP_