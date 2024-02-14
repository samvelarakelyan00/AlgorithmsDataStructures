"""
|------------------|
|Exponential Search|
|------------------|
--------------------------
    Time complexity
    ---------------
        O(log n)


    Space complexity
    ----------------
        O(log n)
 
 
        It's because binary_search is implemented with recursion
        otherwise it will be O(1)
    worst-case  time compleasity   -->  O(log n)
    average     time compleaxity   -->  O(log n)
    best-case   time compleaxity   -->  O(1)
    worst-case  space complexity   -->  O(1)
------------------------------
    Explanation
    -----------
        Works only on sorted arrays
        Exponential search involves two steps:
        1) Find range where element is present
        2) Do Binary Search in above found range.
        The idea is to start with subarray size 1, compare its last element with required value,
        then try size 2, then 4 and so on until last element of a subarray is not greater.
        Once we find an index i (after repeated doubling of i), we know that the element must be present
        between i/2 and i (Why i/2? because we could not find a greater value in previous iteration)
        Given below are the implementations of above steps.
        Exponential Binary Search is particularly useful for unbounded searches,
        where size of array is infinite.
        It works better than Binary Search for bounded arrays, and also when
        the element to be searched is closer to the first element.
"""


def exponentialSearch(sortedArr: "list[int]", targetValue: int):
    if len(sortedArr) == 0:
        return -1
    if sortedArr[0] == targetValue:
        return 0
    i = 1
    while i < len(sortedArr) and sortedArr[i] <= targetValue:
        i *= 2

    return binarySearchRecursion(sortedArr, i//2, min(i, len(sortedArr) - 1), targetValue)


def binarySearchRecursion(sortedArr: "list[int]", left: int, right: int, targetValue: int):
    if left > right:
        return -1
    middle = left + (right - left) // 2
    if sortedArr[middle] == targetValue:
        return middle
    if sortedArr[middle] > targetValue:
        return binarySearchRecursion(sortedArr, left, middle - 1, targetValue)
    return binarySearchRecursion(sortedArr, middle + 1, right, targetValue)
