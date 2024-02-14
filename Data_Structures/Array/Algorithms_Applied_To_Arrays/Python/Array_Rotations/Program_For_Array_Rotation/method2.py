import array


"""
  METHOD 2 (Rotate one by one)
  ----------------------------

    leftRotate(arr[], d, n)
    start
    For i = 0 to i < d
        Left rotate all elements of arr[] by one
    end

    To rotate by one, store arr[0] in a temporary variable temp,
        move arr[1] to arr[0], arr[2] to arr[1] …and finally temp to arr[n-1]
            Let us take the same example arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2
            Rotate arr[] by one 2 times
            We get [2, 3, 4, 5, 6, 7, 1] after first rotation and
            [ 3, 4, 5, 6, 7, 1, 2] after second rotation.
"""


def leftRotateArrayBy1(myArray):
    """
    Fuction to left rotate arr[]
    of size n by 1
    """
    tmp = myArray[0]
    for i in range(len(myArray) - 1):
        myArray[i] = myArray[i + 1]

    myArray[-1] = tmp


def leftRotateArrayByD(myArray, d):
    """
    Fuction to left roteate arr[]
    size n by d
    """
    for i in range(d):
        leftRotateArrayBy1(myArray)


myArray = array.array('i', [1, 2, 3, 4, 5, 6, 7])
print(f"Array before rotate: {myArray}")

leftRotateArrayByD(myArray, 2)
print(f"Array after rotate: {myArray}")
