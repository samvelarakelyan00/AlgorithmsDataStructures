/*
In an unsorted array, the search operation
can be performed by linear traversal
from the first element to the last element. 
*/


#include <iostream>


int findElement(int arr[], int length, int key);
void printArray(int arr[], int length);


int main(int argc, char* argv[]){

    int arr[] = {12, 34, 10, 6, 40};
    int length = sizeof(arr) / sizeof(arr[0]);
    int key1 = 10;
    int key2 = 55;

    std::cout << "Array!\n";
    printArray(arr, length);
    std::cout << "\n";

    int position1 = findElement(arr, length, key1);
    int position2 = findElement(arr, length, key2);

    // Checking for position1
    if (position1 != -1)
        std::cout << "Element " << key1 << " found at index " << position1 << std::endl;
    else
        std::cout << "Element" << key1 << " doesn't exist in the array!\n";
    
    // Checking for position2
    if (position2 != -1)
        std::cout << "Element " << key2 << " found at index " << position2 << std::endl;
    else
        std::cout << "Element " << key2 << " doesn't exist in the array!\n";




    return 0;
}


int findElement(int arr[], int length, int key){
    for (int i = 0; i < length; i++)
        if (arr[i] == key)
            return i;
    return -1;
}


void printArray(int arr[], int length){
    std::cout << "[";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << "]\n";
}
