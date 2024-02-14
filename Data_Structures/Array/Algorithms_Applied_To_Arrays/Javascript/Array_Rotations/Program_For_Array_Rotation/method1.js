/*
    METHOD 1 (using temp array)
    ---------------------------
        Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7
            1) Store the first d elements in a temp array
            temp[] = [1, 2]
            2) Shift rest of the arr[]
            arr[] = [3, 4, 5, 6, 7, 6, 7]
            3) Store back the d elements
            arr[] = [3, 4, 5, 6, 7, 1, 2]
*/


/**
 * function rotate(arr[], n, d)
 * that rotates arr[] of size n by d elements.
 * For Example:
 *  array -> [1, 2, 3, 4, 5, 6, 7]
 *  Rotation of the above array by 2 will make array [3, 4, 5, 6, 7, 1, 2]
*/
let leftRotateArrayByD = function(arr, d){
    // storing 1st D elements in temporary array
    let temp = Array(d).fill(0);
    for (let i = 0;i < d; i++){
        temp[i]=arr[i];
    }

    // shifting remaining elements of the array
    let x = 0;
    for(let j = d; j < arr.length; j++){
        arr[x] = arr[j];
        x++;
    }
    // storing back the D elements to the orignal array
    x = 0;
    for (let k = arr.length - d; k < arr.length; k++){
        arr[k] = temp[x];
        x++;
    }
}


let arr = [1, 2, 3, 4, 5, 6, 7]
console.log(`Array before rotate: ${arr}`)
leftRotateArrayByD(arr, 2)
console.log(`Array after rotate: ${arr}`)
