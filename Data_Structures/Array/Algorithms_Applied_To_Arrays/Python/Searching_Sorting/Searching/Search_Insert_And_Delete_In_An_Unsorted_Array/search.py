"""
In an unsorted array, the search operation
can be performed by linear traversal
from the first element to the last element.
"""


def findElement(arr, elem):
    for i in range(len(arr)):
        if arr[i] == elem:
            return i
    return -1


arr = [12, 34, 10, 6, 40]
key1 = 10
key2 = 55

print(f"Array!\n{arr}")

position1 = findElement(arr, key1)
position2 = findElement(arr, key2)

# Checking for position1
if position1 != -1:
    print(f"Element {key1} found at index {position1}")
else:
    print(f"Element {key1} doesn't exist in the array!")

# Checking for position2
if position2 != -1:
    print(f"Element {key2} found at index {position2}")
else:
    print(f"Element {key2} doesn't exist in the array!")
