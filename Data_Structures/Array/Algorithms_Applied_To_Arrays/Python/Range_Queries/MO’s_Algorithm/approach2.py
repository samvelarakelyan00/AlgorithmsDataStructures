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
    Sort all queries in a way that queries with L values from 0 to √n – 1
    are put together, then all queries from √n to 2*√n – 1, and so on.
    All queries within a block are sorted in increasing order of R values.
    Process all queries one by one in a way that every query uses sum
    computed in the previous query.
    Let ‘sum’ be sum of previous query.
    Remove extra elements of previous query.
    For example if previous query is [0, 8] and current query is [3, 9],
    then we subtract a[0],a[1] and a[2] from sum
    Add new elements of current query.
    In the same example as above, we add a[9] to sum.
"""


def querySum(arr, query):
    allQuerySum = []
    # query.sort(): # Sort by left
    # sort all queries so that all queries in the
    # increasing order of right values.
    query.sort(key=lambda x: x[1])

    # Initialize current L, current R and current sum
    currentLeft, currentRight, currentSum = 0, 0, 0

    # Traverse through all queries
    for i in range(len(query)):
        left, right = query[i]  # left and rigth values of current range

        # Remove extra elements from previous range
        # if previous range is [0, 3] and current
        # range is [2, 5], then a[0] and a[1] are subtracted
        while currentLeft < left:
            currentSum -= arr[currentLeft]
            currentLeft += 1

        # Add elements of current range
        while currentLeft > left:
            currentSum += arr[currentLeft-1]
            currentLeft -= 1
        while currentRight <= right:
            currentSum += arr[currentRight]
            currentRight += 1

        # Remove elements of previous range
        # when previous range is [0, 10] and current range
        # is [3, 8], then a[9] and a[10] are subtracted
        while currentRight > right + 1:
            currentSum -= arr[currentRight-1]
            currentRight -= 1

        # Print the sum of current range
        allQuerySum += [currentSum]

    return query, allQuerySum


arr = [1, 1, 2, 1, 3, 4, 5, 2, 8]
query = [[0, 4], [1, 3], [2, 4]]

allQuerySum = querySum(arr, query)[1]
sortedQueries = querySum(arr, query)[0]

for i in range(len(sortedQueries)):
    print(f"Sum Of {sortedQueries[i]} is {allQuerySum[i]}")
