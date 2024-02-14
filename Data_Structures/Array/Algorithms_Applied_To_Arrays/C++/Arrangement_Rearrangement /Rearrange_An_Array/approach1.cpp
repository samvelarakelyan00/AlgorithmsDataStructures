/*
    Problem Explonation:
    -------------------
        Given an array of elements of length N, ranging from 0 to N – 1.
        All elements may not be present in the array.
        If the element is not present then there will be -1 present in the array.
        Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.

        Examples:
        --------

            Input : arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1}
            Output : [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]

            Input : arr = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
                        11, 10, 9, 5, 13, 16, 2, 14, 17, 4}
            Output : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                    11, 12, 13, 14, 15, 16, 17, 18, 19]

================================================================================

    Approach Explonation (Native Approach):
    --------------------------------------
        1) Nav­i­gate the numbers from 0 to n-1.
        2) Now navigate through array.
        3) If (i==a[j]) , then replace the element at i position with a[j] position.
        4) If there is any element in which -1 is used instead of the number
            then it will be replaced automatically.
        5) Now, iterate through the array and check if (a[i]!=i),
            if it s true then replace a[i] with -1.
        
        Time Complexity:
        ---------------
            O(n^2)
*/

#include <iostream>


void fixArray(int arr[], int length);
void printArray(int arr[], int length);


int main(int argc, char* argv[]){

    int arr1[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    int length1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Original array:\n";
    printArray(arr1, length1);
    fixArray(arr1, length1);
    std::cout << "array after calling function!\n";
    printArray(arr1, length1);
    std::cout << "=====================\n";

    int arr2[] = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8, 11, 10, 9, 5, 13, 16, 2, 14, 17, 4};
    int length2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Original array:\n";
    printArray(arr2, length2);
    fixArray(arr2, length2);
    std::cout << "array after calling function!\n";
    printArray(arr2, length2);



    return 0;
}


void fixArray(int arr[], int length){
    // Iterate over the array
    for (int i = 0; i < length; i++){
        // Check is any arr[j]
        // exists such that
        // arr[j] is equal to i
        for (int j = 0; j < length; j++){
            if (arr[j] == i){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                break;
            }
        }
    }
    // Iterate over array
    for (int i = 0; i < length; i++)
        // If not present
        if (arr[i] != i)
            arr[i] = -1;
}


void printArray(int arr[], int length){
    std::cout << "[";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << "]\n";
}
