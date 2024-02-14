/*
Problem Explonation:
-------------------
    We are given an array and a set of query ranges,
    we are required to find the sum of every query range.

    Example:
    -------
        Input:  arr[]   = {1, 1, 2, 1, 3, 4, 5, 2, 8};
                query[] = [0, 4], [1, 3] [2, 4]
        Output: Sum of arr[] elements in range [0, 4] is 8
                Sum of arr[] elements in range [1, 3] is 4
                Sum of arr[] elements in range [2, 4] is 6


Approach Explonation:
--------------------
    Sort all queries in a way that queries with L values from 0 to √n – 1
    are put together, then all queries from √n to 2*√n – 1, and so on.
    All queries within a block are sorted in increasing order of R values.
    Process all queries one by one in a way that every query uses sum
    computed in the previous query.
    Let ‘sum’ be sum of previous query.
    Remove extra elements of previous query.
    For example if previous query is [0, 8] and current query is [3, 9],
    then we subtract a[0],a[1] and a[2] from sum
    Add new elements of current query.
    In the same example as above, we add a[9] to sum.
*/


class Query{
    constructor(left, right){
        this.left = left;
        this.right = right;
    }
}


function querySum(arr, query, m){
    let allQuerySum = [];
    // One by one compute sum of all queries
    for (let i = 0; i < m; i++){
        // Left and right boundaries of current range
        let left = query[i].left, right = query[i].right;

        // Compute sum of currnent query range
        let sum = 0;
        for (let j = left; j <= right; j++){
            sum += arr[j];
        }

        allQuerySum.push(sum);
    }

    return allQuerySum;
}


let arr = [1, 1, 2, 1, 3, 4, 5, 2, 8];
let query = [];
query.push(new Query(0,4));
query.push(new Query(1,3));
query.push(new Query(2,4));
let m = query.length;
let allQuerySum = querySum(arr, query, m);


for (let i = 0; i < m; i++){
    console.log(`Sum of [${query[i].left}, ${query[i].right}] is ${allQuerySum[i]}`);
}
