/*
|-----------|
|Bubble Sort|
|-----------|
---------------------------------
    Time complexity
    ---------------
        O(n^2)
    Space complexity
    ----------------
        O(n) -> total
        O(1) -> auxiliary
    worst-case  time  complexity   -->  O(n^2)
    average     time  complexity   -->  O(n^2)
    best-case   time  complexity   -->  O(n)
    worst-case  space compleaxity  -->  O(n) - total, O(1) - auxiliary
    best-csae   space complexity   -->  O(n)
---------------------------------
    Explanation
    -----------
        Bubble sort is a simple sorting algorithm that repeatedly steps through the list,
        compares adjacent elements and swaps them if they are in the wrong order.
        The pass through the list is repeated until the list is sorted.
            The simple algorithm performs poorly in real world sue and is used primarily educational tool.
*/
#include <stdio.h>
#include <stdbool.h>

#define SIZE 10


void swap(int *firstPointer, int *secondPointer);
void bubbleSort(int arr[], int length);
void printArray(int arr[], int length);
void testsBubbleSort();


int main(int argc, char* argv[]){

    testsBubbleSort();


    return 0;
}


void swap(int *firstPointer, int *secondPointer){
    int tmp = *firstPointer;
    *firstPointer = *secondPointer;
    *secondPointer = tmp;
}


void bubbleSort(int arr[], int length){
    int i, j;
    bool swapped = false;
    for (i = 0; i < length - 1; i++){
        for (j = 1; j < length; j++){
            if (arr[j] < arr[j - 1]){
                swap(&arr[j], &arr[j - 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
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


bool checkEquality(int arr1[], int arr2[], int length){
    int i;
    for (i = 0; i < length; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}


void testsBubbleSort(){
    bool stillOK = false;
    int arr1[SIZE] = {3, 5, 6, 2, 8, 1, 7, 4, 10, 9};
    int arr2[0] = {};
    int arr3[SIZE] = {-23, 0, 4, -1, 432, 8724, -48, 1415, 2, -66};

    printf("arr1[]:  ");
    printArray(arr1, SIZE);
    printf("arr2[]:  ");
    printArray(arr2, 0);
    printf("arr3[]:  ");
    printArray(arr3, SIZE);
    printf("\n");

    int expectedResult1[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int expectedResult2[0] = {};
    int expectedResult3[SIZE] = {-66, -48, -23, -1, 0, 2, 4, 432, 1415, 8724};

    bubbleSort(arr1, SIZE);
    bubbleSort(arr2, 0);
    bubbleSort(arr3, SIZE);


    // Test 1
    if (checkEquality(arr1, expectedResult1, SIZE))
        printf("Test1 passed!\n");
    else
        printf("Test1 failure!\n");
    printf("Sorted arr1[]:\t");
    printArray(arr1, SIZE);
    printf("\n");

    // Test 2
    if (checkEquality(arr2, expectedResult2, 0))
        printf("Test2 passed!\n");
    else
        printf("Test2 failure!\n");
    printf("Sorted arr2[]:\t");
    printArray(arr2, 0);
    printf("\n");

    // Test 3
    if (checkEquality(arr3, expectedResult3, SIZE))
        printf("Test3 passed!\n");
    else
        printf("Test3 failure!\n");
    printf("Sorted arr3[]:\t");
    printArray(arr3, SIZE);
}
