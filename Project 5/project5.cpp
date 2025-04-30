/*
 * CSC-301
 * project5.cpp
 * Spring 2025
 *
 * Partner 1:
 * Partner 2:
 * Date:
 */

#include "project5.hpp"

using namespace std;

/*
 * EDkernel - fill the (i,j) entry of the table.
 *    Note: numCols input for ease of indexing.
 */
void EDkernel(string &src, string &dest, bool useASM, int numCols,
                     vector<int> &table, int i, int j) {
    return;
}

/*
 * EDhusk - create and iteratively fill the table in the correct order.
 */
vector<int> EDhusk(string &src, string &dest, bool useASM) {
    // Get string lengths for ease of use.
    int n = src.length();
    int m = dest.length();
    int numCols = m+1;

    // Setup the table, size (n+1)x(m+1), filled with 0s.
    vector<int> table( (n+1)*(m+1), 0 );
    
    return table;
}

/*
 * getNumEdits - given a filled table, return the min number of edits.
 */
int getNumEdits(string &src, string &dest, vector<int> &table) {
    int numEdits;
    return numEdits;
}

/*
 * getEdits - reconstruct the optimal edits given a filled table.
 */
vector<Edit> getEdits(string &src, string &dest, vector<int> &table) {
    vector<Edit> edits;
    return edits;
}

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
string printTable(string &src, string &dest, vector<int> &table) {
    // Create the stringstream for the table.
    stringstream tableString;

    // Shift the first row for the dest letters and write the letters.
    // tableString << setw(labelWidth) << fixed;
    tableString << " " << " " << " " << " ";
    for (int j=0; j<dest.length(); j++) {
        // tableString << setprecision(prec) << setw(numWidth) << fixed;
        tableString << dest[j] << " ";
    }
    tableString << endl;

    // Write each line of the table, with the proper src letter at front.
    for (int i=0; i<src.length()+1; i++) {
        // tableString << setw(labelWidth) << fixed;
        if (i > 0) {
            tableString << src[i-1] << " ";
        } else {
            tableString << " " << " ";
        }
        for (int j=0; j<dest.length()+1; j++) {
            // tableString << setprecision(prec) << setw(numWidth) << fixed;
            tableString << table[i*(dest.length()+1) + j] << " ";
        }
        tableString << endl;
    }
    tableString << endl;

    return tableString.str();
}