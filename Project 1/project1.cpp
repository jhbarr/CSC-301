/*
 * CSC-301
 * project1.cpp
 * Spring 2025
 *
 * Partner 1:
 * Partner 2:
 * Date:
 */

#include "project1.hpp"

using namespace std;

/*
 * selectionSort
 Input: vector<double> &arrayToSort - This is a pointer to a vector / array
 Output: None
 This functions performs selection sort (in-place) on the given array
 */
void selectionSort(vector<double> &arrayToSort)
{
    double positiveInfinity = numeric_limits<double>::max();

    // Establish the minimum value and its place in the array
    double min = positiveInfinity;
    double min_location = positiveInfinity;

    // Iterate through the entire array once
    for (int i = 0; i < arrayToSort.size(); i++)
    {
        // Iterate through the unsorted portion of the array
        for (int j = i; j < arrayToSort.size(); j++)
        {
            // Find the next minimum value and swap it into place
            if (arrayToSort[j] < min)
            {
                min = arrayToSort[j];
                min_location = j;
            }
        }
        double temp = arrayToSort[i];
        arrayToSort[i] = min;
        arrayToSort[min_location] = temp;

        // Reset the min value for the next pass
        min = positiveInfinity;
    }

    return;
}

/*
 * insertionSort
* Input: vector<double> &arrayToSort - This is a pointer to a vector / array
* Output: None
* This function performs insertion sort (in-place) on the given vector

 */
void insertionSort(vector<double> &arrayToSort)
{
    // Iterate through the entire array once
    for (int i = 0; i < arrayToSort.size(); i++)
    {
        // Bubble the next value into the correct place relative to the sorted portion
        for (int j = i; j > 0; j--)
        {
            double current = arrayToSort[j];
            double left = arrayToSort[j - 1];

            // Swap two out of place elements
            if (current < left)
            {
                arrayToSort[j - 1] = current;
                arrayToSort[j] = left;
            }
            else
            {
                break;
            }
        }
    }

    return;
}

/*
 * bubbleSort
 * Input: vector<double> &arrayToSort - This is a pointer to a vector / array
 * Output: None
 * This function performs bubble sort (in-place) on the given array
 */
void bubbleSort(vector<double> &arrayToSort)
{
    // Return if it is a singleton array
    if (arrayToSort.size() == 1)
        return;

    // Iterate through the array until no bubbles are performed
    // Meaning that the list is sorted
    bool bubbled;
    do
    {
        bubbled = false;
        // Iterate through the array
        for (int i = 0; i < arrayToSort.size() - 1; i++)
        {
            // Swap two elements that are out of order
            double current = arrayToSort[i];
            double right = arrayToSort[i + 1];

            if (right < current)
            {
                arrayToSort[i] = right;
                arrayToSort[i + 1] = current;
                bubbled = true;
            }
        }
    } while (bubbled);

    return;
}

/*
 * merge
 * Input: array1, array2 - These are two arrays of type 'double'
 * Output: result - An array of type 'double'
 * This is a helper function for merge sort. This merges the two given arrays into one larger, sorted array.
 * This function assumes that the two given arrays are already in sorted order
 */
vector<double> merge(vector<double> array1, vector<double> array2)
{
    vector<double> result;

    // Add the next smallest element from either list
    while (!array1.empty() && !array2.empty())
    {
        if (array1[0] < array2[0])
        {
            result.push_back(array1[0]);
            array1.erase(array1.begin());
        }
        else
        {
            result.push_back(array2[0]);
            array2.erase(array2.begin());
        }
    }

    // Once one of the arrays are empty, add the rest of the other one to the result array

    // If array1 is empty
    if (array1.empty())
    {
        for (int i = 0; i < array2.size(); i++)
        {
            result.push_back(array2[i]);
        }
    }

    // If array 2 is empty
    if (array2.empty())
    {
        for (int i = 0; i < array1.size(); i++)
        {
            result.push_back(array1[i]);
        }
    }

    return result;
}

/*
 * mergeSort
 * Input: vector<double> &arrayToSort - This is a pointer to a vector / array
 * Output: None
 * This function performs the merge sort algorithm (out of place) on the given array
 */
void mergeSort(vector<double> &arrayToSort)
{
    // Return if the array is a singleton
    if (arrayToSort.size() == 1)
        return;

    // Swap the two elements if they are out of order
    if (arrayToSort.size() == 2)
    {
        double left = arrayToSort[0];
        double right = arrayToSort[1];

        if (right < left)
        {
            arrayToSort[0] = right;
            arrayToSort[1] = left;
        }

        return;
    }

    // Split arrayToSort into two smaller arrays
    vector<double> array1;
    vector<double> array2;

    for (int i = 0; i < arrayToSort.size(); i++)
    {
        if (i < arrayToSort.size() / 2)
        {
            array1.push_back(arrayToSort[i]);
        }
        else
        {
            array2.push_back(arrayToSort[i]);
        }
    }

    // Recursively sort the two smaller arrays
    mergeSort(array1);
    mergeSort(array2);

    // Merge the two sorted arrays and assign that to arrayToSort
    arrayToSort = merge(array1, array2);

    return;
}

/*
 * quickSortHelper
 *
 * Note that i is inclusive (i.e., is the first element of subarray).
 * Note that j is not inclusive (i.e., off the end of the subarray).
 *
 */
void quickSortHelper(vector<double> &arrayToSort, int i, int j)
{
    if ((j - i) == 1)
    {
        return;
    }
    else if ((j - i) == 2)
    {
        int right = arrayToSort[j - 1];
        int left = arrayToSort[i];

        if (right < left)
        {
            arrayToSort[j - 1] = left;
            arrayToSort[i] = right;
        }
        return;
    }

    int partition_location = (i + j) / 2;
    double partition_value = arrayToSort[partition_location];

    int start = i;
    int end = j - 1;
    bool stop = false;
    while (!stop)
    {
        while (arrayToSort[start] < partition_value)
        {
            start++;
        }
        while (arrayToSort[end] > partition_value)
        {
            end--;
        }

        if (arrayToSort[start] == arrayToSort[end] && arrayToSort[start] == partition_value && start != end)
        {
            start++;
        }
        else if (start == end)
        {
            stop = true;
        }
        else
        {
            double temp = arrayToSort[start];
            arrayToSort[start] = arrayToSort[end];
            arrayToSort[end] = temp;
        }
    }

    quickSortHelper(arrayToSort, i, start);
    quickSortHelper(arrayToSort, start, j);

    return;
}

/*
 * quickSort
 */
void quickSort(vector<double> &arrayToSort)
{
    quickSortHelper(arrayToSort, 0, arrayToSort.size());
    return;
}
