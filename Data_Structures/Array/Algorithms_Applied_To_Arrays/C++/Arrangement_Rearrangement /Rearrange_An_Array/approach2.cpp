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

===============================================================================

    Approach Explonation:
    --------------------
        1. Nav­i­gate through the array. 
        2. Check if arr[i] = -1, if yes then ignore it. 
        3. If arr[i] != -1, Check if element arr[i] is at its cor­rect posi­tion (i=arr[i]).
            If yes then ignore it. 
        4. If arr[i] != -1 and ele­ment arr[i] is not at its cor­rect posi­tion (i!=arr[i])
            then place it to its correct posi­tion, but there are two conditions:

            I)  Either A[i] is vacate, means A[i] = -1, then just put A[i] = i.
            II) arr[i] is not vacate, means arr[i] = x, then int y = x put arr[i] = i.
                Now, we need to place y to its cor­rect place, so repeat from step 3.
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
    for (int i = 0; i < length; i++){
        if (arr[i] != -1 && arr[i] != i){
            int x = arr[i];

            // check if desired place
            // is not vacate
            while (arr[x] != -1 && arr[x] != x){
                // store the value from
                // desired place
                int y = arr[x];

                // place the x to its correct
                // position
                arr[x] = x;

                // now y will become x, now
                // search the place for x
                x = y;
            }
            // place the x to its correct
            // position
            arr[x] = x;

            // check if while loop hasn't
            // set the correct value at arr[i]
            if (arr[i] != i)
                arr[i] = -1;
        }
    }
}


void printArray(int arr[], int length){
    std::cout << "[";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << "]\n";
}
