"""
|--------------|
|Insertion Sort|
|--------------|
------------------------
    Time complexity
    ---------------
        O(n^2)


    Space complexity
    ----------------
        O(n)



    worst case   time complexity   -->  O(n^2) and swaps
    average      time complexity   -->  O(n^2) and swaps
    best case    time complexity   -->  O(n), O(1) swaps
    worst case   space complexity  -->  O(n), O(1) auxilary
-----------------------------


    Explanation
    -----------
        Insertion sort works similar to the way you sort playing cards in your hands.
        The list is virtually split into a sorted and unsorted parts. Value from the
        unsorted part are picked and placed at the current position in the sorted part.
            Sorting is tipically done in-place, by iterating up the list, growing the sorted
        list behind it. At each list position, it checks the value there against the largest
        value in the sorted list. If larger, it leaves the element in place and moves to the next.
        If smaller, it finds the correct positoin within the sorted list, shifts all the larger
        values up to make a space, and insert into that correct position.
"""
def insertion_sort(myList: list):
    """
    Function to sorting list to ascending order


    Arguments:
    ---------
        positional:
            myList: 'list' --> The list we wont to sorted

    Returns:
    -------
        'None'
    """
    for i in range(1, len(myList)):
        key = myList[i]
        j = i - 1

        while j >= 0 and myList[j] > key:
            myList[j + 1] = myList[j]
            j -= 1

        myList[j + 1] = key

