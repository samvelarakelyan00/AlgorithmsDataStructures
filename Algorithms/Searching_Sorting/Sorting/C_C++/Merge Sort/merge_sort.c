/*
|----------|
|Merge Sort|
|----------|
--------------------------------------------------------
    Time complexity
    ---------------
        O(n * log(n))


    Space complexity
    ----------------
        O(n)


    wosrt case  time  complexity  -  O(n * log(n))
    average     time  complexity  -  O(n * log(n))
    best  case  time  complexity  -  O(n * log(n))
    worst case  space complexity  -  O(n)
----------------------------------------------------------
    Explanation
    -----------
        Merge sort is a divide and coccuer algorithm that was invented by Jhon von Neumann in 1945.
        A Merge Sort works as follows:
            1)Divide the unsorted list into n sublists. each one element
            2)Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining
*/
#include <stdio.h>
#include <stdbool.h>


void mergeSort(int arr[], int low, int high);
void merge(int arr[], int left, int middle, int right);
void printArray(int arr[], int length);
void testsMergeSort();


int main(int argc, char* argv[]){

    testsMergeSort();



    return 0;
}


void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
 
    /* create temp arrays */
    int leftArray[n1], rightArray[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArray[j] = arr[middle + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int left, int right)
{
    if (left < right){
        // Same as (left+right)/2, but avoids overflow for
        // large low and high
        int middle = left + (right - left) / 2;
 
        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
 
        merge(arr, left, middle, right);
    }
}


void printArray(int arr[], int length){
    int i;
    printf("{");
    for (i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    printf("}\n");
}


int checkEquality(int arr1[], int arr2[], int length){
    int i;
    for (i = 0; i < length; i++){
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}


void testsMergeSort(){
    int arr1[10] = {9, 4, 7, 0, 3, 1, 6, 2, 8, 5};
    int arr2[0] = {};
    int arr3[10] = {12, 538, -35, 2733, 0, -7, 33333, 65550, -45720, 1};
    int length1 = sizeof(arr1) / sizeof(arr1[0]);
    int length2 = sizeof(arr2) / sizeof(arr2[0]);
    int length3 = sizeof(arr3) / sizeof(arr3[0]);


        // TEST 1
    int expectedResult1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("Unsorted array: ");
    printArray(arr1, length1);
    mergeSort(arr1, 0, length1 - 1);
    printf("Sorted array:   ");
    printArray(arr1, length1);
    if (checkEquality(arr1, expectedResult1, length1))
        printf("Test1 Passed!\n\n");
    else
        printf("Test1 Failure!\n\n");


        // TEST 2
    int expectedResult2[0] = {};
    printf("Unsorted array: ");
    printArray(arr2, length2);
    mergeSort(arr2, 0, length2 - 1);
    printf("Sorted array:   ");
    printArray(arr2, length2);
    if (checkEquality(arr2, expectedResult2, length2))
        printf("Test2 Passed!\n\n");
    else
        printf("Test2 Failure!\n\n");


        // TEST 3
    int expectedResult3[10] = {-45720, -35, -7, 0, 1, 12, 538, 2733, 33333, 65550};
    printf("Unsorted array: ");
    printArray(arr3, length3);
    mergeSort(arr3, 0, length3 - 1);
    printf("Sorted array:   ");
    printArray(arr3, length3);
    if (checkEquality(arr3, expectedResult3, length3))
        printf("Test3 Passed!\n\n");
    else
        printf("Test3 Failure!\n\n");
}