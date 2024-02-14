#include <iostream>

/*
    METHOD 1 (using temp array)
    ---------------------------
        Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7
            1) Store the first d elements in a temp array
            temp[] = [1, 2]
            2) Shift rest of the arr[]
            arr[] = [3, 4, 5, 6, 7, 6, 7]
            3) Store back the d elements
            arr[] = [3, 4, 5, 6, 7, 1, 2]
*/

/**
 * function rotate(arr[], n, d)
 * that rotates arr[] of size n by d elements.
 * For Example:
 *  array -> [1, 2, 3, 4, 5, 6, 7]
 *  Rotation of the above array by 2 will make array [3, 4, 5, 6, 7, 1, 2]
*/
void leftRotateArrayByD(int *arr, int length, int d);

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


void leftRotateArrayByD(int *arr, int length, int d)
{
  // storing 1st D elements in temporary array
  int temp[d];
  for (int i=0;i<d;i++){
    temp[i]=arr[i];
  }
  
  // shifting remaining elements of the array
  int x=0;
  for(int j=d;j<length;j++){
    arr[x]=arr[j];
    x++;
  }
  
  // storing back the D elements to the orignal array
  x=0;
  for (int k=length-d;k<length;k++){
    arr[k]=temp[x];
    x++;
  }
}


void printArray(int arr[], int length){
    std::cout << "[";
    for (int i = 0; i < length; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "]\n";
}
