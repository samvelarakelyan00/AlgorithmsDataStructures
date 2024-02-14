/*
|-----------|
|Jump Search|
|-----------|
-----------------------

    Time Complexity : O(√n)
    Auxiliary Space : O(1)
    -------------------------

    Explanation
    -----------
        The basic idea is to check fewer elements (then linear search) by jumping ahead
        by fixed steps or skipping some elements in place of searching all elements.
            For example, suppose we have an array of size n and to be jumped size m.
        Then we search at the indexes array[0], array[m], array[2m]...array[km] and so on.
        Once we find the interval(array[km] < x < array[k + 1]m), we perform a linear search operation
        from the index km to find the element x.
        Total number of comparisons in the worst case will be (n / m) + m - 1. The value of the function
        (n / m) + m - 1 will be minimum when m = n ^ (1 / 2). Therefor, the best step size is m = n ^ (1 / 2).
            Important points
            ----------------
                1)Works only sorted array.
                2)The optimal size of a block to be jumpt is n ^ (1 / 2).
                    This makes the time complexity of Jump Search is n ^ (1 / 2)
                3)The time complexity of Jump Search is between Linear Search(O(n))
                    and Binary Search(O(log n)).
                4)Binary Search is better than Jump Search, but Jump Search has an advantage that we traverse back only once
                (Binary Search may require up to O(Log n) jumps, consider a situation where the element to be searched is the
                smallest element or smaller than the smallest).
*/
#include <iostream>
#include <cmath>


/** 
 * Returns
 * -------
 *     'int' --> index of value or -1 if value not found in given array
*/
int jumpSearch(int sortedArr[], int length, int targetValue);
void printArray(int arr[], int length);
void testsJumpSearch();

int main(int argc, char* argv[]){

    testsJumpSearch();




    return 0;
}


int jumpSearch(int sortedArr[], int length, int targetValue){
    // Finding block size to be jumped
    int jumpSize = sqrt(length);

    // Finding the block where element is present (if it's present)
    int left = 0;
    while (sortedArr[std::min(jumpSize, length) - 1] < targetValue){
        left = jumpSize;
        jumpSize += sqrt(length);

        if (left >= length)
            return -1;
    }

    // Doing a linear search for targetValue in block beginning with left
    while (sortedArr[left] < targetValue){
        left++;

        // If we reached next block or end of
        // array, element is not present.
        if (left == std::min(jumpSize, length))
            return -1;
    }

    // If element is found
    if (sortedArr[left] == targetValue)
        return left;
    return -1;
}


void printArray(int arr[], int length){
    std::cout << "{";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << ' ';
    std::cout << "}\n";
}


void testsJumpSearch(){
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[0] = {};
    int arr3[16] = {-89, -54, -23, 0, 2, 5, 10, 36, 78, 192, 198, 201, 205, 248, 260, 300};

    int res1 = jumpSearch(arr1, sizeof(arr1) / sizeof(arr1[0]), 5);
    int res2 = jumpSearch(arr2, sizeof(arr2) / sizeof(arr2[0]), 5);
    int res3 = jumpSearch(arr3, sizeof(arr3) / sizeof(arr3[0]), 36);
    int res4 = jumpSearch(arr1, sizeof(arr1) / sizeof(arr1[0]), -7);
    int res5 = jumpSearch(arr3, sizeof(arr3) / sizeof(arr3[0]), 1024);

    std::cout << "arr1:  ";
    printArray(arr1, sizeof(arr1) / sizeof(arr1[0]));
    std::cout << "arr2:  ";
    printArray(arr2, sizeof(arr2) / sizeof(arr2[0]));
    std::cout << "arr3:  ";
    printArray(arr3, sizeof(arr3) / sizeof(arr3[0]));
    std::cout << "\n";


        // TEST 1
    std::cout << "\tTEST 1!\nSearching number 5 in arr1[]\n";
    if (res1 == 4){
        std::cout << "Index of number 5 in arr1[] is: " << res1 << std::endl;
        std::cout << " TEST 1 PASSED!\n";
    }
    else{
        std::cerr << "Expected result is 4 but got " << res1 << std::endl;
        std::cout << "TEST 1 FAILURE\n";
    }
    std::cout << "------------------------\n\n";


        // TEST 2
    std::cout << "\tTEST 2!\nSearching number 5 in arr2[]\n";
    if (res2 == -1){
        std::cout << "Index of number 5 in arr2[] is: " << res2 << std::endl;
        std::cout << " TEST 2 PASSED!\n";
    }
    else{
        std::cerr << "Expected result is -1 but got " << res2 << std::endl;
        std::cout << "TEST 2 FAILURE\n";
    }
    std::cout << "------------------------\n\n";


        // TEST 3
    std::cout << "\tTEST 3!\nSearching number 36 in arr3[]\n";
    if (res3 == 7){
        std::cout << "Index of number 36 in arr3[] is: " << res3 << std::endl;
        std::cout << " TEST 3 PASSED!\n";
    }
    else{
        std::cerr << "Expected result is 7 but got " << res3 << std::endl;
        std::cout << "TEST 3 FAILURE\n";
    }
    std::cout << "------------------------\n\n";


        // TEST 4
    std::cout << "\tTEST 4!\nSearching number -7 in arr1[]\n";
    if (res4 == -1){
        std::cout << "Index of number 5 in arr2[] is: " << res4 << std::endl;
        std::cout << " TEST 2 PASSED!\n";
    }
    else{
        std::cerr << "Expected result is -1 but got " << res4 << std::endl;
        std::cout << "TEST 4 FAILURE\n";
    }
    std::cout << "------------------------\n\n";


        // TEST 5
    std::cout << "\tTEST 5!\nSearching number 1024 in arr3[]\n";
    if (res5 == -1){
        std::cout << "Index of number 1024 in arr2[] is: " << res5 << std::endl;
        std::cout << " TEST 5 PASSED!\n";
    }
    else{
        std::cerr << "Expected result is -1 but got " << res5 << std::endl;
        std::cout << "TEST 5 FAILURE\n";
    }
}
