/*
|--------------|
|Linear Search |
|--------------|
    Time complexity
    ---------------
        O(n)
    Space complexity
    ----------------
        O(1)
    worst-case  time complexity    -->  O(n)
    average     time complexity    -->  O((n + 1) / 2)
    best-case   time complexity    -->  O(1)
    worst-case  space compleaxity  -->  O(1)
----------------------------
    Explanation
    -----------
        Linear search is very simple search algorithm. In this type of search, a sequential search is
        made over all items one by one. Every item is checked and if a match is fount then that particular
        item's position is returned, otherwise the search continues till the end of the data collection.
*/
#include <iostream>
#include <bits/stdc++.h>

/**
*Function to search in iterable data structure.
*    Arguments
*    ---------
*        positional:
*            arr[]: 'int[]'
*            length: 'int' --> length of the given array
*            targetValue: 'int' --> the value wich we want to find in given array
*    Returns
*    -------
*        'int' --> index of target value
*If target value not found in given array, then function returns -1
*/
int linear_search(int arr[], int length, int targerValue);


int main(int argc, char* argv[]){
/*
    Examples
*/
    const int SIZE = 10;

// Example 1
    int res1, targetValue1, lengthOfArray1 = 0, arr1[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    lengthOfArray1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "arr1[]:  {";
    for (int i = 0; i < lengthOfArray1; i++){
        std::cout << arr1[i] << ' ';
    }
    std::cout << '}' << std::endl;
    targetValue1 = 5;
    res1 = linear_search(arr1, lengthOfArray1, targetValue1); // Returns 4 (index of value in arr1[])
    std::cout << "Index of " << targetValue1 << " in arr1[] is: " << res1 << std::endl;
    std::cout << std::endl;


// Example 2
    int res2, targetValue2, lengthOfArray2 = 0, arr2[0] = {};
    lengthOfArray2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "arr2[]:  {";
    for (int i = 0; i < lengthOfArray2; i++){
        std::cout << arr2[i] << ' ';
    }
    std::cout << '}' << std::endl;
    targetValue2 = 5;
    res2 = linear_search(arr2, lengthOfArray2, targetValue2); // Returns -1
    std::cout << "Index of " << targetValue2 << " in arr2[] is: " << res2 << std::endl;
    std::cout << std::endl;

// Example 3
    int res3, targetValue3, lengthOfArray3 = 0, arr3[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    lengthOfArray3 = sizeof(arr3) / sizeof(arr3[0]);
    std::random_shuffle(arr3, arr3 + lengthOfArray3);
    std::cout << "arr3[]:  {";
    for (int i = 0; i < lengthOfArray3; i++){
        std::cout << arr3[i] << ' ';
    }
    std::cout << '}' << std::endl;
    targetValue3 = 8;
    res3 = linear_search(arr3, lengthOfArray3, targetValue3);
    std::cout << "Index of " << targetValue3 << " in arr2[] is: " << res3 << std::endl;
    std::cout << std::endl;


// Example 4
    int res4, targetValue4, lengthOfArray4 = 0, arr4[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    lengthOfArray4 = sizeof(arr4) / sizeof(arr4[0]);
    std::cout << "arr4[]:  {";
    for (int i = 0; i < lengthOfArray4; i++){
        std::cout << arr4[i] << ' ';
    }
    std::cout << '}' << std::endl;
    targetValue4 = 1024;
    res4 = linear_search(arr4, lengthOfArray4, targetValue4); // Returns -1
    std::cout << "Index of " << targetValue4 << " in arr4[] is: " << res4 << std::endl;
    std::cout << std::endl;



    return 0;
}


int linear_search(int arr[], int length, int targetValue){
    for (int i = 0; i < length; i++){
        if (arr[i] == targetValue){
            return i;
        }
    }
    return -1;
}