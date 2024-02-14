/*
    Problem Explonation:
    -------------------
        Given an array and a number k where k is smaller than the size of the array,
        we need to find the k’th smallest element in the given array.
        It is given that all array elements are distinct.

        Examples:
        --------
            Input: arr[] = {7, 10, 4, 3, 20, 15} 
            k = 3 
            Output: 7

            Input: arr[] = {7, 10, 4, 3, 20, 15} 
            k = 4 
            Output: 10
    

    Approach Explonation(using set from C++ STL):
    -------------------------------------
        We can find the kth smallest element in time complexity better than O(N * log(N)). 
        We know the Set in C++ STL is implemented using Binary Search Tree
        and we also know that the time compexity of all
        cases(searching , inserting, deleting ) in BST is log (n) in average case
        and O(n) in worst case.
        We are using set because it is mentioned in the question that
        all the elements in array re distinct

        Time Complexity:
        ---------------
            Worst Case:       O(N)
            Average Case:     O(Log(N))
            Auxiliary Space:  O(N)
*/

#include <iostream>
#include <set>


int k_thSmallest(int arr[], int length, int k);
void printArray(int arr[], int length);


int main(int argc, char* argv[]){
int arr[] = { 12, 3, 5, 7, 19 };
    int length = sizeof(arr) / sizeof(arr[0]), k = 3;
    std::cout << "Original array!\n";
    printArray(arr, length);
    int smallest = k_thSmallest(arr, length, k);
    std::cout << k << "_th smallest element in the given array!\n";
    std::cout << smallest << std::endl;



    return 0;
}


int k_thSmallest(int arr[], int length, int k){
    std::set<int> s(arr, arr + length);
    std::set<int>::iterator itr = s.begin();
    advance(itr, k - 1);

    return *itr;
}


void printArray(int arr[], int length){
    std::cout << '[';
    for (int i = 0; i < length; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "]\n";
}
