/*
In the delete operation, the element to be deleted
is searched using the linear search,
and then delete operation is performed followed by shifting the elements. 
*/


function findElement(arr, length, key){
    for (let i = 0; i < length; i++)
        if (arr[i] == key)
            return i;
    return -1;
}


function deleteElement(arr, length, key){
    let position = findElement(arr, length, key);

    // If elemnt found
    if (position != -1){
        // Deleting element
        for (let i = position; i < length - 1; i++){
            arr[i] = arr[i + 1];
        }
        return length - 1;
    }
    return length;
}



function printArray(arr, length){
    resStr = "";
    for (let i = 0; i < length; i++)
        resStr += arr[i] + ",";
    console.log(resStr);
}


let arr = [10, 50, 30, 40, 20];
let length = arr.length;
let key = 30;

console.log(`Array before deleting!\n`)
printArray(arr, length);
let newLength = deleteElement(arr, length, key);
console.log(`Array after deleting ${key}\n`);
printArray(arr, newLength);
