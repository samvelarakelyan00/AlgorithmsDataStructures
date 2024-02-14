"""
Problem Explonation:
-------------------
    We are given an array and a set of query ranges,
    we are required to find the sum of every query range.

    Example:
    -------
        Input:  arr[]   = {1, 1, 2, 1, 3, 4, 5, 2, 8};
                query[] = [0, 4], [1, 3] [2, 4]
        Output: Sum of arr[] elements in range [0, 4] is 8
                Sum of arr[] elements in range [1, 3] is 4
                Sum of arr[] elements in range [2, 4] is 6


Approach Explonation:
--------------------
    A Solution is to run a loop from left to right
    and calculate the sum of elements in given range
    for every query [left, right]

    Time Comlexity:
    --------------
        O(N * M)
            N -> Length of the array
            M -> Length of the range
        worst case: O(N ^ 2)
"""


def querySum(arr, query):
    allQuerySum = []
    for q in query:
        left, right = q
        sumOfCurrentRange = 0

        for i in range(left, right + 1):
            sumOfCurrentRange += arr[i]

        allQuerySum += [sumOfCurrentRange]

    return allQuerySum


arr = [1, 1, 2, 1, 3, 4, 5, 2, 8]
query = [[0, 4], [1, 3], [2, 4]]

allQuerySum = querySum(arr, query)

for i in range(len(query)):
    print(f"Sum Of {query[i]} is {allQuerySum[i]}")
