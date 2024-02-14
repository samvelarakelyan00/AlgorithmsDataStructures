import array


"""
    METHOD 1 (using temp array)
    ---------------------------
        Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n = 7
            1) Store the first d elements in a temp array
            temp[] = [1, 2]
            2) Shift rest of the arr[]
            arr[] = [3, 4, 5, 6, 7, 6, 7]
            3) Store back the d elements
            arr[] = [3, 4, 5, 6, 7, 1, 2]
"""


def leftRotateArrayByD(myArray, d):
    """
    function rotate(arr[], n, d)
    that rotates arr[] of size n by d elements.

        For Example:
            array -> [1, 2, 3, 4, 5, 6, 7]
            Rotation of the above array by 2 will
            make array [3, 4, 5, 6, 7, 1, 2]
    """
    tmpArray = array.array('i', [0] * d)
    for i in range(d):
        tmpArray[i] = myArray[i]

    x = 0
    for j in range(d, len(myArray)):
        myArray[x] = myArray[j]
        x += 1

    x = 0
    for k in range(len(myArray) - d, len(myArray)):
        myArray[k] = tmpArray[x]
        x += 1


myArray = array.array('i', [1, 2, 3, 4, 5, 6, 7])
print(f"Array before rotate: {myArray}")

leftRotateArrayByD(myArray, 2)
print(f"Array after rotate: {myArray}")
