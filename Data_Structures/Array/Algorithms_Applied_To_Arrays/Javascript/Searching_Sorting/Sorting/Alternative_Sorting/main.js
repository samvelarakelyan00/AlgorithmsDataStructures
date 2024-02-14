/*
Problem Explonation:
-------------------
    Given an array of integers, print the array in such a way
    that the first element is first maximum
    and second element is first minimum and so on.

    Examples:
    --------
        Input : arr[] = {7, 1, 2, 3, 4, 5, 6}
        Output : 7 1 6 2 5 3 4

        Input : arr[] = {1, 6, 9, 4, 3, 7, 8, 2}
        Output : 9 1 8 2 7 3 6 4

Approach Explonation:
--------------------
    A simple solution is to first print maximum element,
    then minimum, then second maximum, and so on.
    Time complexity of this approach is O(N ^ 2).
    An efficient solution involves following steps. 
    1) Sort input array using a O(N * Log(N)) algorithm.
    2) We maintain two pointers, one from beginning
        and one from end in sorted array.
        We alternatively print elements pointed
        by two pointers and move them toward each other.
*/


function alternativeSort(arr){
    resultString = "";
    // Sorting array
    arr.sort((a, b) => a - b);

    let i = 0, j = arr.length - 1;

    while (i < j)
        resultString += `${arr[j--]},${arr[i++]},`;
    
    if (arr.length % 2)
        resultString += arr[i];
    
    return resultString;
}

let arr1 = [7, 1, 2, 3, 4, 5, 6];
let arr2 = [1, 6, 9, 4, 3, 7, 8, 2];

console.log(`arr1 before sorting: ${arr1}`);
resultString = alternativeSort(arr1);
console.log(`arr1 after soring: ${resultString}`);
console.log("\n");
console.log(`arr2 before sorting: ${arr2}`);
resultString = alternativeSort(arr2);
console.log(`arr2 after soring: ${resultString}`);

