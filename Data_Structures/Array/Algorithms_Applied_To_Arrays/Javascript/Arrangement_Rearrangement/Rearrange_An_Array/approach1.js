/*
    Problem Explonation:
    -------------------
        Given an array of elements of length N, ranging from 0 to N – 1.
        All elements may not be present in the array.
        If the element is not present then there will be -1 present in the array.
        Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.

        Examples:
        --------

            Input : arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1}
            Output : [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]

            Input : arr = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
                        11, 10, 9, 5, 13, 16, 2, 14, 17, 4}
            Output : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                    11, 12, 13, 14, 15, 16, 17, 18, 19]

================================================================================

    Approach Explonation (Native Approach):
    --------------------------------------
        1) Nav­i­gate the numbers from 0 to n-1.
        2) Now navigate through array.
        3) If (i==a[j]) , then replace the element at i position with a[j] position.
        4) If there is any element in which -1 is used instead of the number
            then it will be replaced automatically.
        5) Now, iterate through the array and check if (a[i]!=i),
            if it s true then replace a[i] with -1.
        
        Time Complexity:
        ---------------
            O(n^2)
*/

function fixArray(arr){
    // Iterate over the array
    for (let i = 0; i < arr.length; i++){
        // Check is any arr[j]
        // exists such that
        // arr[j] is equal to i
        for (let j = 0; j < arr.length; j++){
            if (arr[j] == i){
                let temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                break;
            }
        }
    }
    // Iterate over array
    for (let i = 0; i < arr.length; i++)
        // If not present
        if (arr[i] != i)
            arr[i] = -1;
}


let arr1 = [-1, -1, 6, 1, 9, 3, 2, -1, 4, -1];
console.log(`Original array:\n${arr1}`)
fixArray(arr1);
console.log(`Array after calling function!\n${arr1}`);
console.log("======================");

let arr2 = [19, 7, 0, 3, 18, 15, 12, 6, 1, 8, 11, 10, 9, 5, 13, 16, 2, 14, 17, 4];
console.log(`Original array:\n${arr2}`)
fixArray(arr2);
console.log(`Array after calling function!\n${arr2}`);
