"""
|---------------|
|Selection Sort |
|---------------|

-----------------------
    Time complexity
    ---------------
        O(n^2)


    Space complexity
    ----------------
        O(1) auxiliary


    worst case   time complexity   -->  O(n^2), O(n) swaps
    average      time complexity   -->  O(n^2), O(n) swaps
    best-case    time complexity   -->  O(n^2), O(1) swaps
    wost-case    space complexity  -->  O(1) auxiliary
-----------------------------


    Explanation
    -----------
        The algorithm divides the input list into two parts: a sorted sublist of items which is built up
        form left to right at the front of the list and a sublist of the remaining unsorted items that occupy
        the rest of the list. Initially the sorted sublist is empty and the unsorted sublist is the entire
        input list. The algorithm proceeds by finding the smallest(or largest, depending on sorting order)
        element in the unsorted sublist, swapping it with the leftmost unsorted element, and
        moving the sublist boundeirs one element tothe right.
"""
def selection_sort(myList: list):
    """
    Function to sorting list of real numbers.

    Arguments:
    ---------
        positional:
            myList: 'list' --> The list of real numbers, wich we want to sorted in ascending order

    Returns:
    -------
        'None'
    """
    for i in range(len(myList) - 1):
        minIndex = i #The index of minimum number in unsorted sublist. First it first element in unsorted sublist

        for j in range(i + 1, len(myList)):
            if myList[j] < myList[minIndex]: #trying find element in unsorted sublist, wich smallest than first element of unsorted sublist
                minIndex = j

        myList[i], myList[minIndex] = myList[minIndex], myList[i]

