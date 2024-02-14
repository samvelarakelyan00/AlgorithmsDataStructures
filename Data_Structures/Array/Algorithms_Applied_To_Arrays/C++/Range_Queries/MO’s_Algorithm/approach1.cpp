/*
Problem Explonation:
-------------------
    We are given an array and a set of query ranges,
    we are required to find the sum of every query range.

    Example:
    -------
        Input:  arr[]   = {1, 1, 2, 1, 3, 4, 5, 2, 8};
                query[] = [0, 4], [1, 3] [2, 4]
        Output: Sum of arr[] elements in range [0, 4] is 8
                Sum of arr[] elements in range [1, 3] is 4
                Sum of arr[] elements in range [2, 4] is 6


Approach Explonation:
--------------------
    Sort all queries in a way that queries with L values from 0 to √n – 1
    are put together, then all queries from √n to 2*√n – 1, and so on.
    All queries within a block are sorted in increasing order of R values.
    Process all queries one by one in a way that every query uses sum
    computed in the previous query.
    Let ‘sum’ be sum of previous query.
    Remove extra elements of previous query.
    For example if previous query is [0, 8] and current query is [3, 9],
    then we subtract a[0],a[1] and a[2] from sum
    Add new elements of current query.
    In the same example as above, we add a[9] to sum.
*/


#include <iostream>


// Structure to represent a query range
struct Query
{
    int left, rigth;
};


void querySum(int arr[], int length, Query q[], int m);
void printArray(int arr[], int length);


int main(int argc, char* argv[]){

    int arr[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
    int length = sizeof(arr) / sizeof(arr[0]);
    Query q[] = {{0, 4}, {1, 3}, {2, 4}};
    int m = sizeof(q) / sizeof(q[0]);
    std::cout << "Array:\n";
    printArray(arr, length);
    std::cout << "\n";

    querySum(arr, length, q, m);



    return 0;
}


void querySum(int arr[], int length, Query q[], int m){
    // One by one compute sum of all queries
    for (int i = 0; i < m; i++){
        // Left and right boundaries of current range
        int left = q[i].left, right = q[i].rigth;

        // Compute sum of current query range
        int sum = 0;
        for (int j = left; j <= right; j++)
            sum += arr[j];
        
        // Print sum of current query range
        std::cout << "Sum of [" << left << ", "
            << right << "] is "  << sum << std::endl;
    }
}


void printArray(int arr[], int length){
    std::cout << "[";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << "]\n";
}       
