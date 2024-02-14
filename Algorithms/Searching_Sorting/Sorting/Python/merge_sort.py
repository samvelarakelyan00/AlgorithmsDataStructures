"""
|----------|
|Merge Sort|
|----------|
--------------------------------------------------------
    Time complexity
    ---------------
        O(n * log(n))


    Space complexity
    ----------------
        O(n)


    wosrt case  time  complexity  -  O(n * log(n))
    average     time  complexity  -  O(n * log(n))
    best  case  time  complexity  -  O(n * log(n))
    worst case  space complexity  -  O(n)
----------------------------------------------------------


    Explanation
    -----------
        Merge sort is a divide and coccuer algorithm that was invented by Jhon von Neumann in 1945.
        A Merge Sort works as follows:
            1)Divide the unsorted list into n sublists. each one element
            2)Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining
"""
def merge(list1: list, list2: list):
    """
    Function to merge two lists

    Arguments:
    ---------
        positional:
            list1: 'list' --> first  list of numbers
            list2: 'list' --> second lsit of numbers

    Returns:
    -------
        'list' --> merge of two given lists(accending order)
    """
    res_list = []
    l1_index, l2_index = 0, 0

    while l1_index < len(list1) and l2_index < len(list2):
        if list1[l1_index] < list2[l2_index]:
            res_list.append(list1[l1_index])
            l1_index += 1
        else:
            res_list.append(list2[l2_index])
            l2_index += 1
    if l1_index == len(list1):
        res_list.extend(list2[l2_index:])
    else:
        res_list.extend(list1[l1_index:])

    return res_list


def merge_sort(list_of_numbers: list):
    """
    Function to sorting given list in accending order

    Aeguments:
    ---------
        positional
            list_of_numbers: 'list' --> The list of numbers which we want to sorted in accending order

    Returns:
    -------
        'list' --> The given list sorted in accending order


    This function is a recursive function, which uses the <merge()> helper function
    """
    if len(list_of_numbers) <= 1:
        return list_of_numbers

    left = merge_sort(list_of_numbers[:len(list_of_numbers) // 2])
    right = merge_sort(list_of_numbers[len(list_of_numbers) // 2:])

    return merge(left, right)

