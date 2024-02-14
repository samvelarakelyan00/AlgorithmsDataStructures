"""
Insert at the end:
-----------------
    In an unsorted array, the insert operation
    is faster as compared to a sorted array
    because we don’t have to care about the
    position at which the element is to be placed.
"""


def insertElement(arr, elem):
    arr.append(elem)


arr = [12, 16, 20, 40, 50, 70]
key = 1000
print(f"Array before insertion: {arr}")
insertElement(arr, key)
print(f"Array after insertion: {arr}")
