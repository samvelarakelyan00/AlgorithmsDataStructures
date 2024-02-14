/*
In an unsorted array, the search operation
can be performed by linear traversal
from the first element to the last element. 
*/


function findElement(arr, key){
    for (let i = 0; i < arr.length; i++)
        if (arr[i] == key)
            return i;
    return -1;
}


let arr = [12, 34, 10, 6, 40];
let key1 = 10;
let key2 = 55;

console.log(`Array!\n${arr}\n`);

let position1 = findElement(arr, key1);
let position2 = findElement(arr, key2);

// Checking for position1
if (position1 != -1)
    console.log(`Element ${key1} found at index ${position1}`);
else
    console.log(`Element ${key1} doesn't exist in the array!`);

// Checking for position2
if (position2 != -1)
    console.log(`Element ${key2} found at index ${position2}`);
else
    console.log(`Element ${key2} doesn't exist in the array!`);

