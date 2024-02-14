/*
|---------------------|
|Interpolation Search |
|---------------------|
---------------------------------
    Time complexity
    ---------------
        worst case -  O(n)
        best  case -  O(log(log n))
    Space complexity
    ----------------
        O(1)
----------------------------------
    Explanation
    -----------
        The Interpolation Search is an improvement over Binary Search sor instance, where the
        values in a sorted array are uniformaly distributed. Binary Search always goes to the
        middle elelment to check but Interpolation Search may go to different locations according
        to the value of the key being searched.
            To be find position to be searched, it used following formula:
        |-------------------------------------------------------------------------------------------|
        |position = start + [((end - start) * (key - arrray[start])) / (array[end] - array[start])] |
        |-------------------------------------------------------------------------------------------|
            where:  start -->  starting index in array
                    end   -->  ending index in array
                    key   -->  element to be searched
            The idea of formula is to return higher value of position when element to be searched
            is closer to array[end], and smaller value when closer to array[start].
        Algorithm:
            step1: In a loop, calculate the value of position using the probe position formula.
            step2: If it is a match, return the index of the item, and exit.
            step3: If the item is less than array[position], calculate the probe position of the left
                    subarray. Otherwise calculate the same in the right subarray.
            step4: Repeate until a match is found or the subarray reduces to zero.
-------------------------------------------------------------------------------------------------------------
    |=======================================|
    |Mathematical derivation of the formula |
    |=======================================|
            Suppose we have a linear function y = f(x) and two points:
                point1 -> (x1, y1)
                point2 -> (x2, y2)
            where y1 = f(x1) and
                  y2 = f(x2) and
                  any x1 < x2
        -------------------------------------
        Suppose we want to find an x where x1 <= x <= x2
        tan(alpha) = (y2 - y1) / (x2 - x1)|
                                          |  ==> (y2 - y1) / (x2 - x1) = (y - y1) / (x - x1)
        tan(alpha) = (y - y1) / (x - x1)  |
                                                                     ||
                                                                     ||
                                                                     \/
                                                    y = y1 + [(y2 - y1) * (x - x1) / x - x1]
                                                                        or
                                                    x = x1 + [(x2 - x1) * (y - y1) / (y2 - y1)]

        x1 -> start     and  y1 ->  array[start]
        x2 -> end       and  y2 ->  array[end]
        x  -> position  and  y  ->  array[position] i.e. required value (key)
                                    ||
                                    \/
    |---------------------------------------------------------------------------------------|
    |position = start + [(end - start) * (key - array[start]) / (array[end] - array[start])]|
    |---------------------------------------------------------------------------------------|
*/
#include <stdio.h>


/**
 * Function to searching element in given array
 * Arguments:
 *     positional:
 *         arr[]:          'array' -->  The array where we want searching element
 *         length:         'int'   -->  Length of array
 *         required_value: 'int'   -->  The value, wich we want to search
 * Returns:
 * -------
 *     'int' --> Position of requierd value or -1 if value not found in given array
*/
const int interpolationSearch(int arr[], int length, int requiredValue);
void printArray(int arr[], int length);
void testsInterpolationSearch();


int main(int argc, char* argv[]){

    testsInterpolationSearch();



    return 0;
}


const int interpolationSearch(int arr[], int length, int requiredValue){
    int start = 0, end = length - 1, position;
    while (start <= end){
        if (arr[start] == arr[end]){
            if (arr[start] == requiredValue)
                return start;
            return -1;
        }
        position = start + ((end - start) * (requiredValue - arr[start])) / (arr[end] - arr[start]);
        if (arr[position] == requiredValue)
            return position;
        else if (arr[position] > requiredValue)
            end = position - 1;
        else
            start = position + 1;
    }
    return -1;
}


void printArray(int arr[], int length){
    printf("{");
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("}\n");
}


void testsInterpolationSearch(){
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[0] = {};
    int arr3[16] = {-89, -54, -23, 0, 2, 5, 10, 36, 78, 192, 198, 201, 205, 248, 260, 300};

    int res1 = interpolationSearch(arr1, sizeof(arr1) / sizeof(arr1[0]), 5);
    int res2 = interpolationSearch(arr2, sizeof(arr2) / sizeof(arr2[0]), 5);
    int res3 = interpolationSearch(arr3, sizeof(arr3) / sizeof(arr3[0]), 36);
    int res4 = interpolationSearch(arr1, sizeof(arr1) / sizeof(arr1[0]), -7);
    int res5 = interpolationSearch(arr3, sizeof(arr3) / sizeof(arr3[0]), 1024);

    printf("arr1:  ");
    printArray(arr1, sizeof(arr1) / sizeof(arr1[0]));
    printf("arr2:  ");
    printArray(arr2, sizeof(arr2) / sizeof(arr2[0]));
    printf("arr3:  ");
    printArray(arr3, sizeof(arr3) / sizeof(arr3[0]));
    printf("\n");


        // TEST 1
    printf("\tTEST 1!\nSearching number 5 in arr1[]\n");
    if (res1 == 4){
        printf("Index of number 5 in arr1[] is: %d\n", res1);
        printf(" TEST 1 PASSED!\n");
    }
    else{
        printf("Expected result is 4 but got %d\n", res1);
        printf("TEST 1 FAILURE\n");
    }
    printf("------------------------\n\n");


        // TEST 2
    printf("\tTEST 2!\nSearching number 5 in arr2[]\n");
    if (res2 == -1){
        printf("Index of number 5 in arr2[] is: %d\n", res2);
        printf(" TEST 2 PASSED!\n");
    }
    else{
        printf("Expected result is -1 but got %d\n", res2);
        printf("TEST 2 FAILURE\n");
    }
    printf("------------------------\n\n");


        // TEST 3
    printf("\tTEST 3!\nSearching number 36 in arr3[]\n");
    if (res3 == 7){
        printf("Index of number 36 in arr3[] is: %d\n", res3);
        printf(" TEST 3 PASSED!\n");
    }
    else{
        printf("Expected result is 7 but got %d\n", res3);
        printf("TEST 3 FAILURE\n");
    }
    printf("------------------------\n\n");


        // TEST 4
    printf("\tTEST 4!\nSearching number -7 in arr1[]\n");
    if (res4 == -1){
        printf("Index of number 5 in arr2[] is: %d\n", res4);
        printf(" TEST 2 PASSED!\n");
    }
    else{
        printf("Expected result is -1 but got %d\n", res4);
        printf("TEST 4 FAILURE\n");
    }
    printf("------------------------\n\n");


        // TEST 5
    printf("\tTEST 5!\nSearching number 1024 in arr3[]\n");
    if (res5 == -1){
        printf("Index of number 1024 in arr2[] is: %d\n", res5);
        printf(" TEST 5 PASSED!\n");
    }
    else{
        printf("Expected result is -1 but got %d\n", res5);
        printf("TEST 5 FAILURE\n");
    }
}
