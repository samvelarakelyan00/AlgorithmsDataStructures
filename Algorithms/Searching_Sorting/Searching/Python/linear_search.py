"""
|--------------|
|Linear Search |
|--------------|


    Time complexity
    ---------------
        O(n)

    Space complexity
    ----------------
        O(1)


    worst-case  time complexity    -->  O(n)
    average     time complexity    -->  O((n + 1) / 2)
    best-case   time complexity    -->  O(1)
    worst-case  space compleaxity  -->  O(1)
----------------------------



    Explanation
    -----------
        Linear search is very simple search algorithm. In this type of search, a sequential search is
        made over all items one by one. Every item is checked and if a match is fount then that particular
        item's position is returned, otherwise the search continues till the end of the data collection.
"""
def linear_search(myList: list, targetValue) -> int:
    """
    Function to search in iterable data structure.

    Arguments
    ---------
        positional:
            myList: 'list'
            targetValue: 'any type' --> the value wich we want to find in given list

    Returns
    -------
        'int' --> index of target value

    If target value not found in given list, then function returns -1
    """
    for index in range(len(myList)):
        if myList[index] == targetValue:
            return index
    return -1

