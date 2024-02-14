/*
    Problem Explonation:
    -------------------
        Given an array and a number k where k is smaller than the size of the array,
        we need to find the k’th smallest element in the given array.
        It is given that all array elements are distinct.

        Examples:
        --------
            Input: arr[] = {7, 10, 4, 3, 20, 15} 
            k = 3 
            Output: 7

            Input: arr[] = {7, 10, 4, 3, 20, 15} 
            k = 4 
            Output: 10
    

    Approach Explonation(Simple Solution):
    -------------------------------------
        A simple solution is to sort the given array
        using a O(N log N) sorting algorithm like Merge Sort, Heap Sort, etc,
        and return the element at index k-1 in the sorted array. 

        Time Complexity:
        ---------------
            O(N * Log(N))
*/

#include <iostream>
#include <algorithm>


int k_thSmallest(int arr[], int length, int k);
void printArray(int arr[], int length);


int main(int argc, char* argv[]){
    
    int arr[] = { 12, 3, 5, 7, 19 };
    int length = sizeof(arr) / sizeof(arr[0]), k = 2;
    std::cout << "Original array!\n";
    printArray(arr, length);
    int smallest = k_thSmallest(arr, length, k);
    std::cout << k << "_th smallest element in the given array!\n";
    std::cout << smallest << std::endl;



    return 0;
}


int k_thSmallest(int arr[], int length, int k){
    // Sort the given array
    std::sort(arr, arr + length);

    // Return k_th element in the sorted array
    return arr[k - 1];
}


void printArray(int arr[], int length){
    std::cout << '[';
    for (int i = 0; i < length; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "]\n";
}
