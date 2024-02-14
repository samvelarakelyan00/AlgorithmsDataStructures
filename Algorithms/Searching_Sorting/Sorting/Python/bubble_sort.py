"""
|-----------|
|Bubble Sort|
|-----------|

---------------------------------
    Time complexity
    ---------------
        O(n^2)


    Space complexity
    ----------------
        O(n) -> total
        O(1) -> auxiliary


    worst-case  time  complexity   -->  O(n^2)
    average     time  complexity   -->  O(n^2)
    best-case   time  complexity   -->  O(n)
    worst-case  space compleaxity  -->  O(n) - total, O(1) - auxiliary
    best-csae   space complexity   -->  O(n)
---------------------------------


    Explanation
    -----------
        Bubble sort is a simple sorting algorithm that repeatedly steps through the list,
        compares adjacent elements and swaps them if they are in the wrong order.
        The pass through the list is repeated until the list is sorted.
            The simple algorithm performs poorly in real world sue and is used primarily educational tool.
"""
def bubble_sort(unsortedList: list):
    swapped = False
    for i in range(len(unsortedList)):
        for j in range(1, len(unsortedList)):
            if unsortedList[j] < unsortedList[j - 1]:
                unsortedList[j], unsortedList[j - 1] = unsortedList[j - 1], unsortedList[j]
                swapped = True
        if not swapped:
            break

