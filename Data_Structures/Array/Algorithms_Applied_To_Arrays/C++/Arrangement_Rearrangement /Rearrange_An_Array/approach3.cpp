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

    Approach Explonation (Using HashSet):
    --------------------------------------
        1) Store all the numbers present in the array into a HashSet 
        2) Iterate through the length of the array,
            if the corresponding position element is present in the HashSet,
            then set arr[i] = i, else arr[i] = -1

*/

#include <iostream>
#include <unordered_map>


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
    // Initialize a hashamp
    std::unordered_map<int, int> hmap;

    // Enter each element in hmap
    for (int i = 0; i < length; i++){
        if (arr[i] != -1)
            hmap[arr[i]] = 1;
    }

    // Navigate through array,
    // and put A[i] = i,
    // if i is present in hmap
    for (int i = 0; i < length; i++){
        // if i(index) is found in hmap
        if (hmap.find(i) != hmap.end())
            arr[i] = i;
        // if not found
        else
            arr[i] = -1;
    }
}


void printArray(int arr[], int length){
    std::cout << "[";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << "]\n";
}
