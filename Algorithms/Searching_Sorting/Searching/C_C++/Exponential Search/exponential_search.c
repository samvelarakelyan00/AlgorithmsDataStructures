/*
|------------------|
|Exponential Search|
|------------------|
--------------------------
    Time complexity
    ---------------
        O(log n)


    Space complexity
    ----------------
        O(log n)
        It's because binary_search is implemented with recursion
        otherwise it will be O(1)


    worst-case  time compleasity   -->  O(log n)
    average     time compleaxity   -->  O(log n)
    best-case   time compleaxity   -->  O(1)
    worst-case  space complexity   -->  O(1)
------------------------------
    Explanation
    -----------
        Works only on sorted arrays
        Exponential search involves two steps:
        1) Find range where element is present
        2) Do Binary Search in above found range.
        The idea is to start with subarray size 1, compare its last element with required value,
        then try size 2, then 4 and so on until last element of a subarray is not greater.
        Once we find an index i (after repeated doubling of i), we know that the element must be present
        between i/2 and i (Why i/2? because we could not find a greater value in previous iteration)
        Given below are the implementations of above steps.
        Exponential Binary Search is particularly useful for unbounded searches,
        where size of array is infinite.
        It works better than Binary Search for bounded arrays, and also when
        the element to be searched is closer to the first element.
*/
#include <stdio.h>


#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

/**
 * Returns index of targetValue or -1 if value doesn't present in a array.
*/
const int exponentialSearch(int sortedArr[], int length, int targetValue);
/**
 * This function ignore a rpeated elements.
 * If target value not found in given array, then function returns -1
*/
const int binarySearchRecursion(int sortedArrayrr[], int left, int right, int targetValue);
void printArray(int arr[], int length);
void testsExponentialSearch();


int main(int argc, char* argv[]){

    testsExponentialSearch();



    return 0;
}


const int exponentialSearch(int sortedArr[], int length, int targetValue){
    if (length == 0)
        return -1;

    if (sortedArr[0] == targetValue)
        return 0;
    
    int i = 1;
    while (i < length && sortedArr[i] <= targetValue)
        i *= 2;
    
    return binarySearchRecursion(sortedArr, i/2, MIN(i, length - 1), targetValue);
}


const int binarySearchRecursion(int sortedArr[], int left, int right, int targetValue){
    if (left > right)
        return -1;
    
    int middle = left + (right - left) / 2;

    if (sortedArr[middle] == targetValue)
        return middle;
    if (sortedArr[middle] < targetValue)
        return binarySearchRecursion(sortedArr, middle + 1, right, targetValue);
    return binarySearchRecursion(sortedArr, left, middle - 1, targetValue);
}


void printArray(int arr[], int length){
    printf("{");
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("}\n");
}


void testsExponentialSearch(){
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[0] = {};
    int arr3[16] = {-89, -54, -23, 0, 2, 5, 10, 36, 78, 192, 198, 201, 205, 248, 260, 300};

    int res1 = exponentialSearch(arr1, sizeof(arr1) / sizeof(arr1[0]), 5);
    int res2 = exponentialSearch(arr2, sizeof(arr2) / sizeof(arr2[0]), 5);
    int res3 = exponentialSearch(arr3, sizeof(arr3) / sizeof(arr3[0]), 36);
    int res4 = exponentialSearch(arr1, sizeof(arr1) / sizeof(arr1[0]), -7);
    int res5 = exponentialSearch(arr3, sizeof(arr3) / sizeof(arr3[0]), 1024);

    printf("arr1:  ");
    printArray(arr1, sizeof(arr1) / sizeof(arr1[0]));
    printf("arr2:  ");
    printArray(arr2, sizeof(arr2) / sizeof(arr2[0]));
    printf("arr3:  ");
    printArray(arr3, sizeof(arr3) / sizeof(arr3[0]));
    printf("\n");


        // TEST 1
    printf("\tTEST 1!\nSearching number 5 in arr1[]\n");
    if (res1 == 4){
        printf("Index of number 5 in arr1[] is: %d\n", res1);
        printf(" TEST 1 PASSED!\n");
    }
    else{
        printf("Expected result is 4 but got %d\n", res1);
        printf("TEST 1 FAILURE\n");
    }
    printf("------------------------\n\n");


        // TEST 2
    printf("\tTEST 2!\nSearching number 5 in arr2[]\n");
    if (res2 == -1){
        printf("Index of number 5 in arr2[] is: %d\n", res2);
        printf(" TEST 2 PASSED!\n");
    }
    else{
        printf("Expected result is -1 but got %d\n", res2);
        printf("TEST 2 FAILURE\n");
    }
    printf("------------------------\n\n");


        // TEST 3
    printf("\tTEST 3!\nSearching number 36 in arr3[]\n");
    if (res3 == 7){
        printf("Index of number 36 in arr3[] is: %d\n", res3);
        printf(" TEST 3 PASSED!\n");
    }
    else{
        printf("Expected result is 7 but got %d\n", res3);
        printf("TEST 3 FAILURE\n");
    }
    printf("------------------------\n\n");


        // TEST 4
    printf("\tTEST 4!\nSearching number -7 in arr1[]\n");
    if (res4 == -1){
        printf("Index of number 5 in arr2[] is: %d\n", res4);
        printf(" TEST 2 PASSED!\n");
    }
    else{
        printf("Expected result is -1 but got %d\n", res4);
        printf("TEST 4 FAILURE\n");
    }
    printf("------------------------\n\n");


        // TEST 5
    printf("\tTEST 5!\nSearching number 1024 in arr3[]\n");
    if (res5 == -1){
        printf("Index of number 1024 in arr2[] is: %d\n", res5);
        printf(" TEST 5 PASSED!\n");
    }
    else{
        printf("Expected result is -1 but got %d\n", res5);
        printf("TEST 5 FAILURE\n");
    }
}
