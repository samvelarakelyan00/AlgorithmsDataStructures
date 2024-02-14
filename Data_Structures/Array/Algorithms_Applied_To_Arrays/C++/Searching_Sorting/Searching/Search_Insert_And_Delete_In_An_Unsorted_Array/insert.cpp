/*
Insert at the end:
-----------------
    In an unsorted array, the insert operation
    is faster as compared to a sorted array
    because we don’t have to care about the
    position at which the element is to be placed.
*/


#include <iostream>


int inserAtTheEnd(int arr[], int length, int elem, int capacity);
void printArray(int arr[], int length);


int main(int argc, char* argv[]){

    int arr[20] = {12, 16, 20, 40, 50, 70};
    int capacity = sizeof(arr) / sizeof(arr[0]);
    int realLengthOfArray = 6;
    int elem = 1000;
    std::cout << "Array before insertion!\n";
    printArray(arr, realLengthOfArray);
    std::cout << std::endl;
    
    // Real length of the array changed after insertion
    realLengthOfArray = inserAtTheEnd(arr, realLengthOfArray, elem, capacity);
    std::cout << "Array after insertion!\n";
    printArray(arr, realLengthOfArray);



    return 0;
}


int inserAtTheEnd(int arr[], int length, int elem, int capacity){
    if (length >= capacity)
        return length;

    arr[length] = elem;
    return length + 1;
}


void printArray(int arr[], int length){
    std::cout << "[";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << "]\n";
}
