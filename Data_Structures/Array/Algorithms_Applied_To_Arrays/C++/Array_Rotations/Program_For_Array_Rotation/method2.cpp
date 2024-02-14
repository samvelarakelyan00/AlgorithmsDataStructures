#include <iostream>

/*
  METHOD 2 (Rotate one by one)
  ----------------------------

    leftRotate(arr[], d, n)
    start
    For i = 0 to i < d
        Left rotate all elements of arr[] by one
    end

    To rotate by one, store arr[0] in a temporary variable temp,
        move arr[1] to arr[0], arr[2] to arr[1] …and finally temp to arr[n-1]
            Let us take the same example arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2 
            Rotate arr[] by one 2 times 
            We get [2, 3, 4, 5, 6, 7, 1] after first rotation and
            [ 3, 4, 5, 6, 7, 1, 2] after second rotation.
*/

/**
 * Fuction to left rotate arr[]
 * of size n by 1
*/
void leftRotateArrayBy1(int arr[], int length);

/**
 * Fuction to left roteate arr[]
 * size n by d
*/
void leftRotateArrayByD(int arr[], int length, int d);

/**
 * Function to print array
*/
void printArray(int arr[], int length);


int main(int argc, char* argv[]){

    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array before rotate!\n";
    printArray(arr, length);

    leftRotateArrayByD(arr, length, 2);
    std::cout << "Array after rotate!\n";
    printArray(arr, length);



    return 0;
}


void leftRotateArrayBy1(int arr[], int length){
    int tmp = arr[0];
    for (int i = 0; i < length - 1; i++)
        arr[i] = arr[i + 1];
    
    arr[length - 1] = tmp;
}


void leftRotateArrayByD(int arr[], int length, int d){
    for (int i = 0; i < d; i++)
        leftRotateArrayBy1(arr, length);
}


void printArray(int arr[], int length){
    std::cout << "[";
    for (int i = 0; i < length; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "]\n";
}
