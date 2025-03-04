/*
 * CSC-301
 * project1.cpp
 * Spring 2025
 *
 * Partner 1: Joseph Barrows
 * Partner 2: Deven Platt
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
    // Create an array to merge the two sorted subarrays into
    vector<double> result;
    // result.reserve(array1.size() + array2.size());

    // Add the smallest element of the two subarrays to the result array
    // While both subarrays are not empty
    int i = 0, j = 0;
    while (i < array1.size() && j < array2.size())
    {
        if (array1[i] < array2[j])
        {
            result.push_back(array1[i++]);
        }
        else
        {
            result.push_back(array2[j++]);
        }
    }

    // Add the rest of each subarray to the result array
    while (i < array1.size())
        result.push_back(array1[i++]);
    while (j < array2.size())
        result.push_back(array2[j++]);

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
    int split = arrayToSort.size() / 2;
    vector<double> array1(arrayToSort.begin(), arrayToSort.begin() + split);
    vector<double> array2(arrayToSort.begin() + split, arrayToSort.end());

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
    if ((j - i) <= 1)
    {
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

    quickSortHelper(arrayToSort, i, end);
    quickSortHelper(arrayToSort, start, j);

    return;
}

/*
 * quickSort
 * Input: vector<double> &arrayToSort - This is a pointer to a vector / array
 * Output: None
 * This function sorts the given array in place using the Quick Sort algorithm
 */
void quickSort(vector<double> &arrayToSort)
{
    quickSortHelper(arrayToSort, 0, arrayToSort.size());
    return;
}
