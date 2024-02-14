/*
Problem Explonation:
-------------------
    Given an array of integers, print the array in such a way
    that the first element is first maximum
    and second element is first minimum and so on.

    Examples:
    --------
        Input : arr[] = {7, 1, 2, 3, 4, 5, 6}
        Output : 7 1 6 2 5 3 4

        Input : arr[] = {1, 6, 9, 4, 3, 7, 8, 2}
        Output : 9 1 8 2 7 3 6 4

Approach Explonation:
--------------------
    A simple solution is to first print maximum element,
    then minimum, then second maximum, and so on.
    Time complexity of this approach is O(N ^ 2).
    An efficient solution involves following steps. 
    1) Sort input array using a O(N * Log(N)) algorithm.
    2) We maintain two pointers, one from beginning
        and one from end in sorted array.
        We alternatively print elements pointed
        by two pointers and move them toward each other.
*/


#include <iostream>
#include <algorithm>


void alternativeSort(int arr[], int length);



int main(int argc, char* argv[]){

    int arr1[] = {7, 1, 2, 3, 4, 5, 6};
    int length1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {1, 6, 9, 4, 3, 7, 8, 2};
    int length2 = sizeof(arr2) / sizeof(arr2[0]);

    alternativeSort(arr1, length1);
    std::cout << std::endl;
    alternativeSort(arr2, length2);
    std::cout << std::endl;



    return 0;
}


void alternativeSort(int arr[], int length){
    // Sorting the array
    std::sort(arr, arr + length);

    int i = 0, j = length - 1;

    while (i < j){
        std::cout << arr[j--];
        std::cout << arr[i++];
    }

    if (length % 2)
        std::cout << arr[i];
}
