"""
|-----------|
|Jump Search|
|-----------|

-----------------------
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
"""
import math

def jump_search(myList: list, value):
    """
    Returns
    -------
        'int' --> index of value or -1 if value not found in given list
    """
    jump_size = math.sqrt(len(myList))
    left = 0

    while myList[int(min(jump_size, len(myList)) - 1)] < value:
        left = jump_size
        jump_size += math.sqrt(len(myList))
        if left > len(myList):
            return -1
    while myList[int(left)] < value:
        left += 1

        if left == min(jump_size, len(myList)):
            return -1
    if myList[int(left)] == value:
        return int(left)
    return -1

