"""
In the delete operation, the element to be deleted
is searched using the linear search,
and then delete operation is performed followed by shifting the elements. 
"""


def deleteElement(arr, elem):
    arr.remove(elem)


arr = [10, 50, 30, 40, 20]
key = 30

print(f"Array before deleting: {arr}")
deleteElement(arr, key)
print(f"Array after deletign: {arr}")
