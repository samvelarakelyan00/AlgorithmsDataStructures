"""
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


    Approach Explonation(Simple Solution):
    -------------------------------------
        A simple solution is to sort the given array
        using a O(N log N) sorting algorithm like Merge Sort, Heap Sort, etc,
        and return the element at index k-1 in the sorted array.

        Time Complexity:
        ---------------
            O(N * Log(N))
"""


def k_thSmallest(arr, k):
    # Sort the given array
    arr.sort()

    # Return k'th element in the sorted array
    return arr[k - 1]


arr = [12, 3, 5, 7, 191]
k = 2
print(f"Original array!\n{arr}")
smallest = k_thSmallest(arr, k)  # 5
print(f"{k}_th smallest element in the given array!\n{smallest}")
