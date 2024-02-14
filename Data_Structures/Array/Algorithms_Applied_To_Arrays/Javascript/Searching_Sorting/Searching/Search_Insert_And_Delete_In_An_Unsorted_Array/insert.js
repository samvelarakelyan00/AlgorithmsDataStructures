/*
Insert at the end:
-----------------
    In an unsorted array, the insert operation
    is faster as compared to a sorted array
    because we don’t have to care about the
    position at which the element is to be placed.
*/


function inserAtTheEnd(arr, length, elem, capacity){
    if (length >= capacity)
        return length;

    arr[length] = elem;
    return length + 1;
}


function printArray(arr, length){
    resStr = "";
    for (let i = 0; i < length; i++)
        resStr += arr[i] + ",";
    console.log(resStr);
}


let arr = new Array(20);
    arr[0] = 12;
    arr[1] = 16;
    arr[2] = 20;
    arr[3] = 40;
    arr[4] = 50;
    arr[5] = 70;
    let capacity = 20;
    let length = 6;
    let elem = 1000;


console.log("Array before insertion!\n");
printArray(arr, length);
// Real length of the array changed after insertion
let newLength = inserAtTheEnd(arr, length, elem, capacity);
console.log("Array after insertion!\n");
printArray(arr, newLength);
