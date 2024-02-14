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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

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
const int linear_search(int arr[], int length, int targerValue);
void swap (int *a, int *b);
void randomize (int arr[], int length);

int main(int argc, char* argv[]){
/*
    Examples
*/
int i;

// Example 1
    int res1, targetValue1, lengthOfArray1 = 0, arr1[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    lengthOfArray1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("arr1[]:  {");
    for (i = 0; i < lengthOfArray1; i++){
        printf("%d ", arr1[i]);
    }
    printf("}\n");
    targetValue1 = 5;
    res1 = linear_search(arr1, lengthOfArray1, targetValue1); // Returns 4 (index of value in arr1[])
    printf("Index of %d in arr1[] is: %d\n", targetValue1, res1);
    printf("\n");


// Example 2
    int res2, targetValue2, lengthOfArray2 = 0, arr2[0] = {};
    lengthOfArray2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("arr2[]:  {");
    for (i = 0; i < lengthOfArray2; i++){
        printf("%d ", arr2[i]);
    }
    printf("}\n");
    targetValue2 = 5;
    res2 = linear_search(arr2, lengthOfArray2, targetValue2); // Returns 4 (index of value in arr2[])
    printf("Index of %d in arr2[] is: %d\n", targetValue2, res2);
    printf("\n");


// Example 3
    int res3, targetValue3, lengthOfArray3 = 0, arr3[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    lengthOfArray3 = sizeof(arr3) / sizeof(arr3[0]);
    randomize(arr3, lengthOfArray3);
    printf("arr3[]:  {");
    for (i = 0; i < lengthOfArray3; i++){
        printf("%d ", arr3[i]);
    }
    printf("}\n");
    targetValue3 = 8;
    res3 = linear_search(arr3, lengthOfArray3, targetValue3);
    printf("Index of %d in arr3[] is: %d\n", targetValue3, res3);
    printf("\n");


// Example 4
    int res4, targetValue4, lengthOfArray4 = 0, arr4[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    lengthOfArray4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("arr4[]:  {");
    for (i = 0; i < lengthOfArray4; i++){
        printf("%d ", arr4[i]);
    }
    printf("}\n");
    targetValue4 = 1024;
    res4 = linear_search(arr4, lengthOfArray4, targetValue4); // Returns -1
    printf("Index of %d in arr4[] is: %d\n", targetValue4, res4);
    printf("\n");



    return 0;
}


const int linear_search(int arr[], int length, int targerValue){
    int i;
    for (i = 0; i < length; i++){
        if (arr[i] == targerValue){
            return i;
        }
    }
    return -1;
}

void swap (int *arr1, int *arr2){
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

void randomize (int arr[], int length){
    srand (time(NULL));
    int i;
    for (i = length - 1; i > 0; i--){
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}
