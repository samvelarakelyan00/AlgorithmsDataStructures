/*
|-------------|
|Binary Search|
|-------------|
---------------------------
    Time complexity
    ---------------
        O(log n)


    Space complexity
    ----------------
        O(1)


    worst-case  time compleasity   -->  O(log n)
    average     time compleaxity   -->  O(log n)
    best-case   time compleaxity   -->  O(1)
    worst-case  space complexity   -->  O(1)
    best-case   space compleaxity  -->  O(1)
---------------------------
    Explanation
    -----------
        Binary search works on sorted arrays. Binary search begins by comparing an element in the middle of the array with the target value.
        If the target value matches the element it's position in the array is returned.
        If the target alue is less than the element, the search continues in the lower half of the array.
        If the target value is greater than the element, the search continus in the upper half of the array.
            By doing this, the algorithm eliminates the half in wich the target value can't lie in each iteration
*/
#include <iostream>


/**
 * This function ignore a rpeated elements.
 * If target value not found in given array, then function returns -1
*/
const int binary_search(int sortedArrayrr[], int length, int targetValue);
/**    
 * If target value repeated in given array, then function returns leftmost element
 * If target value not found in given array, then function returns -1
*/
const int binary_search_leftmost(int sortedArray[], int length, int targetValue);
/**    
 * If target value repeated in given array, then function returns rightmost element
 * If target value not found in given array, then function returns -1
*/
const int binary_search_rightmost(int sortedArray[], int length, int targetValue);


int main(int argc, char* argv[]){
    int arr[10] = {1, 2, 3, 4, 4, 4, 4, 4, 4, 5};
    int target = 4;
    int length = sizeof(arr) / sizeof(arr[0]);
    int bin = binary_search(arr, length, target);
    int binLeft = binary_search_leftmost(arr, length, target);
    int binRight = binary_search_rightmost(arr, length, target);

    std::cout << "Index of element " << target << " (binary_search): " << bin << std::endl;
    std::cout << "Index of element " << target << " (binary_search_leftmost): " << binLeft << std::endl;
    std::cout << "Index of element " << target << " (binary_search_rightmost): " << binRight << std::endl;



    return 0;
}


const int binary_search(int sortedArrayrr[], int length, int targetValue){
    int left = 0;
    int right = length - 1;
    
    while (left <= right){
        int middle = (left + right) / 2;
        if (sortedArrayrr[middle] == targetValue)
            return middle;
        else if (sortedArrayrr[middle] > targetValue)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}


const int binary_search_leftmost(int sortedArray[], int length, int targetValue){
    int left = 0;
    int right = length - 1;
    int idx = -1;

    while (left <= right){
        int middle = (left + right) / 2;
        if (sortedArray[middle] < targetValue)
            left = middle + 1;
        else if (sortedArray[middle] > targetValue)
            right = middle - 1;
        else{
            idx = middle;
            right = middle - 1;
        }
    }
    return idx;
}


const int binary_search_rightmost(int sortedArray[], int length, int targetValue){
    int left = 0;
    int right = length - 1;
    int idx = -1;

    while (left <= right){
        int middle = (left + right) / 2;
        if (sortedArray[middle] < targetValue)
            left = middle + 1;
        else if (sortedArray[middle] > targetValue)
            right = middle - 1;
        else{
            idx = middle;
            left = middle + 1;
        }
    }
    return idx;
}
