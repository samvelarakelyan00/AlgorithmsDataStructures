"""
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
"""
def binary_search(myList: list, target_value: int) -> int:
    """
    This function ignore a rpeated elements.
    If target value not found in given list, then function returns -1
    """
    left = 0
    right = len(myList) - 1

    while left <= right:
        middle = (left + right) // 2
        if myList[middle] == target_value:
            return middle
        if myList[middle] > target_value:
            right = middle - 1
        else:
            left = middle + 1
    return -1




def binary_search_leftmost(myList: list, target_value: int) -> int:
    """
    If target value repeated in given list, then function returns leftmost element
    If target value not found in given list, then function returns -1
    """
    left = 0
    right = len(myList) - 1

    while left < right:
        middle = (left + right) // 2
        if myList[middle] < target_value:
            left = middle + 1
        else:
            right = middle
    return left if myList[left] == target_value else -1




def binary_search_rightmost(myList: list, target_value: int) -> int:
    """
    If target value repeted in given list, then function returns index of rightmost element
    If target value not found in given list, then function returns -1
    """
    left = 0
    right = len(myList) - 1

    while left < right:
        middle = (left + right) // 2
        if myList[middle] > target_value:
            right = middle
        else:
            left = middle + 1
    return right - 1 if myList[right - 1] == target_value else -1

