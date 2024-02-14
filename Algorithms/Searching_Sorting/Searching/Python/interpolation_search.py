"""
|---------------------|
|Interpolation Search |
|---------------------|
---------------------------------
    Time complexity
    ---------------
        worst case -  O(n)
        best  case -  O(log(log n))


    Space complexity
    ----------------
        O(1)

----------------------------------


    Explanation
    -----------
        The Interpolation Search is an improvement over Binary Search sor instance, where the
        values in a sorted array are uniformaly distributed. Binary Search always goes to the
        middle elelment to check but Interpolation Search may go to different locations according
        to the value of the key being searched.
            To be find position to be searched, it used following formula:
        |-------------------------------------------------------------------------------------------|
        |position = start + [((end - start) * (key - arrray[start])) / (array[end] - array[start])] |
        |-------------------------------------------------------------------------------------------|
            where:  start -->  starting index in array
                    end   -->  ending index in array
                    key   -->  element to be searched

            The idea of formula is to return higher value of position when element to be searched
            is closer to array[end], and smaller value when closer to array[start].

        Algorithm:
            step1: In a loop, calculate the value of position using the probe position formula.
            step2: If it is a match, return the index of the item, and exit.
            step3: If the item is less than array[position], calculate the probe position of the left
                    subarray. Otherwise calculate the same in the right subarray.
            step4: Repeate until a match is found or the subarray reduces to zero.
-------------------------------------------------------------------------------------------------------------

    |=======================================|
    |Mathematical derivation of the formula |
    |=======================================|

            Suppose we have a linear function y = f(x) and two points:
                point1 -> (x1, y1)
                point2 -> (x2, y2)
            where y1 = f(x1) and
                  y2 = f(x2) and
                  any x1 < x2
        -------------------------------------
        Suppose we want to find an x where x1 <= x <= x2

        tan(alpha) = (y2 - y1) / (x2 - x1)|
                                          |  ==> (y2 - y1) / (x2 - x1) = (y - y1) / (x - x1)
        tan(alpha) = (y - y1) / (x - x1)  |
                                                                     ||
                                                                     ||
                                                                     \/


                                                    y = y1 + [(y2 - y1) * (x - x1) / x - x1]

                                                                        or

                                                    x = x1 + [(x2 - x1) * (y - y1) / (y2 - y1)]


        x1 -> start     and  y1 ->  array[start]
        x2 -> end       and  y2 ->  array[end]
        x  -> position  and  y  ->  array[position] i.e. required value (key)

                                    ||
                                    \/

    |---------------------------------------------------------------------------------------|
    |position = start + [(end - start) * (key - array[start]) / (array[end] - array[start])]|
    |---------------------------------------------------------------------------------------|

"""
def interpolation_search(myList: list, required_value: int):
    """
    Function to searching element in given list

    Arguments:
        positional:
            myList:         'list' -->  The list where we want searching element
            required_value: 'int'  -->  The value, wich we want to search

    Returns:
    -------
        'int' --> Position of requierd value or -1 if value not found in given list
    """
    start = 0
    end = len(myList) - 1
    while required_value <= myList[end] and required_value >= myList[start] and start <= end:
        if start == end:
            if myList[start] == required_value:
                return start
            return -1

        position = start + int((((end - start) * (required_value - myList[start])) / (myList[end] - myList[start])))

        if myList[position] == required_value:
            return position
        if myList[position] < required_value:
            start = position + 1
        else:
            end = position - 1

    return -1

