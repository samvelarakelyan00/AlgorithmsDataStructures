/*
|---------------|
|Selection Sort |
|---------------|
-----------------------
    Time complexity
    ---------------
        O(n^2)


    Space complexity
    ----------------
        O(1) auxiliary


    worst case   time complexity   -->  O(n^2), O(n) swaps
    average      time complexity   -->  O(n^2), O(n) swaps
    best-case    time complexity   -->  O(n^2), O(1) swaps
    wost-case    space complexity  -->  O(1) auxiliary
-----------------------------
    Explanation
    -----------
        The algorithm divides the input array into two parts: a sorted subarray of items which is built up
        form left to right at the front of the array and a subarray of the remaining unsorted items that occupy
        the rest of the array. Initially the sorted subarray is empty and the unsorted subarray is the entire
        input array. The algorithm proceeds by finding the smallest(or largest, depending on sorting order)
        element in the unsorted subarray, swapping it with the leftmost unsorted element, and
        moving the subarray boundeirs one element tothe right.
*/
#include <iostream>

/**
*  Function to sorting array of integers.
*  Arguments:
*  ---------
*      positional:
*          arr[]: 'int []' --> The array of integers, wich we want to sorted in ascending order
*/
void selectionSort(int arr[], int length);
void printArray(int arr[], int length);
void swap(int *first, int *second);
void testsSelectionSort();
int checkEquality(int arr1[], int arr[2], int length);


int main(int argc, char* argv[]){

    testsSelectionSort();


    
    return 0;
}


void selectionSort(int arr[], int length){
    int minIndex;
    for (int i = 0; i < length - 1; i++){
        // The index of minimum number in unsorted subarray. First it first element in unsorted subarray
        minIndex = i;
        for (int j = i + 1; j < length; j++){
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // trying find element in unsorted subarray, wich smallest than first element of unsorted subarray
        if (minIndex != i){
            swap(&arr[i], &arr[minIndex]);
        }
    }
}


void swap(int *first, int *second){
    int tmp = *first;
    *first = *second;
    *second = tmp;
}


void printArray(int arr[], int length){
    printf("{");
    for (int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    printf("}\n");
}


int checkEquality(int arr1[], int arr2[], int length){
    for (int i = 0; i < length; i++){
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}



void testsSelectionSort(){
    int arr1[10] = {9, 4, 7, 0, 3, 1, 6, 2, 8, 5};
    int arr2[0] = {};
    int arr3[10] = {12, 538, -35, 2733, 0, -7, 33333, 65550, -45720, 1};
    int length1 = sizeof(arr1) / sizeof(arr1[0]);
    int length2 = sizeof(arr2) / sizeof(arr2[0]);
    int length3 = sizeof(arr3) / sizeof(arr3[0]);

        // TEST 1
    int expectedResult1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Unsorted array: ";
    printArray(arr1, length1);
    selectionSort(arr1, length1);
    std::cout << "Sorted array:   ";
    printArray(arr1, length1);
    if (checkEquality(arr1, expectedResult1, length1))
        std::cout << "Test1 Passed!\n\n";
    else
        std::cout << "Test1 Failure!\n\n";


        // TEST 2
    int expectedResult2[0] = {};
    std::cout << "Unsorted array: ";
    printArray(arr2, length2);
    selectionSort(arr2, length2);
    std::cout << "Sorted array:   ";
    printArray(arr2, length2);
    if (checkEquality(arr2, expectedResult2, length2))
        std::cout << "Test2 Passed!\n\n";
    else
        std::cout << "Test2 Failure!\n\n";


        // TEST 3
    int expectedResult3[10] = {-45720, -35, -7, 0, 1, 12, 538, 2733, 33333, 65550};
    std::cout << "Unsorted array: ";
    printArray(arr3, length3);
    selectionSort(arr3, length3);
    std::cout << "Sorted array:   ";
    printArray(arr3, length3);
    if (checkEquality(arr3, expectedResult3, length3))
        std::cout << "Test3 Passed!\n\n";
    else
        std::cout << "Test3 Failure!\n\n";
}
