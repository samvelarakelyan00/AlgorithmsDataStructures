/*
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
*/


/**
 * Fuction to left rotate arr[]
 * of size n by 1
*/
let leftRotateArrayBy1 = function(arr){
    let tmp = arr[0];
    for (let i = 0; i < arr.length - 1; i++)
        arr[i] = arr[i + 1];
    
    arr[arr.length - 1] = tmp;
}


/**
 * Fuction to left roteate arr[]
 * size n by d
*/
let leftRotateArrayByD = function (arr, d){
    for (let i = 0; i < d; i++)
        leftRotateArrayBy1(arr);
}


let arr = [1, 2, 3, 4, 5, 6, 7]
console.log(`Array before rotate: ${arr}`)
leftRotateArrayByD(arr, 2)
console.log(`Array after rotate: ${arr}`)
