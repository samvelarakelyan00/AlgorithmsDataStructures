/*
In the delete operation, the element to be deleted
is searched using the linear search,
and then delete operation is performed followed by shifting the elements. 
*/


#include <iostream>


int findElement(int arr[], int length, int key);
int deleteElement(int arr[], int length, int key);
void printArray(int arr[], int length);


int main(int argc, char* argv[]){

    int arr[] = {10, 50, 30, 40, 20};
    int length = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    std::cout << "Array brfore deleting!\n";
    printArray(arr, length);

    // Array length changed after deleting element
    int newLength = deleteElement(arr, length, key);
    std::cout << "Array after deleting " << key << std::endl;
    printArray(arr, newLength);



    return 0;
}


int findElement(int arr[], int length, int key){
    for (int i = 0; i < length; i++)
        if (arr[i] == key)
            return i;
    return -1;
}


int deleteElement(int arr[], int length, int key){
    int position = findElement(arr, length, key);

    // If elemnt found
    if (position != -1){
        // Deleting element
        for (int i = position; i < length - 1; i++){
            arr[i] = arr[i + 1];
        }

        return length - 1;
    }
    return length;
}


void printArray(int arr[], int length){
    std::cout << "[";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << "]\n";
}
