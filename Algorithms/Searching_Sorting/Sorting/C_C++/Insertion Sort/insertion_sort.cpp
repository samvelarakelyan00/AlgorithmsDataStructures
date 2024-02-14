/*
|--------------|
|Insertion Sort|
|--------------|
------------------------
    Time complexity
    ---------------
        O(n^2)


    Space complexity
    ----------------
        O(n)


    worst case   time complexity   -->  O(n^2) and swaps
    average      time complexity   -->  O(n^2) and swaps
    best case    time complexity   -->  O(n), O(1) swaps
    worst case   space complexity  -->  O(n), O(1) auxilary
-----------------------------
    Explanation
    -----------
        Insertion sort works similar to the way you sort playing cards in your hands.
        The list is virtually split into a sorted and unsorted parts. Value from the
        unsorted part are picked and placed at the current position in the sorted part.
            Sorting is tipically done in-place, by iterating up the list, growing the sorted
        list behind it. At each list position, it checks the value there against the largest
        value in the sorted list. If larger, it leaves the element in place and moves to the next.
        If smaller, it finds the correct positoin within the sorted list, shifts all the larger
        values up to make a space, and insert into that correct position.
*/
#include <iostream>


void insertionSort(int arr[], int length);
void printArray(int arr[], int length);
int checkEquality(int arr1[], int arr2[], int length);
void testsInsertionSort();


int main(int argc, char* argv[]){

    testsInsertionSort();



    return 0;
}

void insertionSort(int arr[], int length){
    int key, j;
    for (int i = 1; i < length; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void printArray(int arr[], int length){
    std::cout << "{";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << ' ';
    std::cout << "}\n";
}


int checkEquality(int arr1[], int arr2[], int length){
    for (int i = 0; i < length; i++){
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}


void testsInsertionSort(){
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
    insertionSort(arr1, length1);
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
    insertionSort(arr2, length2);
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
    insertionSort(arr3, length3);
    std::cout << "Sorted array:   ";
    printArray(arr3, length3);
    if (checkEquality(arr3, expectedResult3, length3))
        std::cout << "Test3 Passed!\n\n";
    else
        std::cout << "Test3 Failure!\n\n";
}
