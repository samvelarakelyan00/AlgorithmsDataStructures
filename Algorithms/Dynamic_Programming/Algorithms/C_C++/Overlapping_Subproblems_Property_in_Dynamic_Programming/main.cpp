/*
Overlapping Subproblems:
========================
    Like Divide and Conquer, Dynamic Programming
    combines solutions to sub-problems.
        Dynamic Programming is mainly used when
        solutions of the same subproblems are needed again and again.
        In dynamic programming, computed solutions to subproblems are
        stored in a table so that these don’t have to be recomputed.
        So Dynamic Programming is not useful when there are no common
        (overlapping) subproblems because there is no point storing
        the solutions if they are not needed again.
        For example, Binary Search doesn’t have common subproblems.
        If we take an example of following recursive program for
        Fibonacci Numbers, there are many subproblems that are
        solved again and again.
*/


#include <iostream>


#define NIL -1
#define MAX 100

int lookup[MAX] = {0};


/**
 *  function for nth Fibonacci number 
*/

int fib(int n);
/** Function to initialize NIL
 * values in lookup table 
*/
void _initialize();

/**
 *  function for nth Fibonacci number 
*/
int fibMemorized(int n);

/**
 *  function for nth Fibonacci number 
*/
int fibTabulated(int n);


int main(int argc, char* argv[]){

    int n = 40;
    _initialize();
    std::cout << "Fibonacci number is " << fibMemorized(n) << std::endl;

    n = 9;
    std::cout << "Fibonacci number is " << fibTabulated(n) << std::endl;



    return 0;
}


// a simple recursive program for Fibonacci numbers
int fib(int n){
    if (n <= 1)
        return n;
 
    return fib(n - 1) + fib(n - 2);
}


/*
Recursion tree for execution of fib(5):
--------------------------------------
                                fib(5)
                              /        \
                          fib(4)        fib(3)
                          /      \       /     \
                      fib(3)      fib(2) fib(2) fib(1)
                      /    \       /    \
                  fib(2)   fib(1) fib(1) fib(0)
                  /     \
              fib(1)  fib(0)

We can see that the function fib(3) is being called 2 times.
If we would have stored the value of fib(3),
then instead of computing it again, we could have reused the old stored value.
There are following two different ways to store the values so that these
values can be reused:
    a) Memorization (Top Down)
    b) Tabulation (Bottom Up)
"*/

// Memoization (Top Down)
/*
The memoized program for a problem is similar to the recursive version
with a small modification that looks into a lookup table before
computing solutions. We initialize a lookup array with all
initial values as NIL. Whenever we need the solution to a subproblem,
we first look into the lookup table.
If the precomputed value is there then we return that value,
otherwise, we calculate the value and put the result in the lookup table
so that it can be reused later.
*/


/* 
    Function to initialize NIL
    values in lookup table 
*/
void _initialize(){
    for (int i = 0; i < MAX; i++)
        lookup[i] = NIL;
}


int fibMemorized(int n){
    if (lookup[n] == NIL){
        if (n <= 1)
            lookup[n] = n;
        else
            lookup[n] = fib(n - 1) + fib(n - 2);
    }

    return lookup[n];
}


// Tabulation (Bottom Up)
/*
The tabulated program for a given problem builds a table in bottom-up fashion
and returns the last entry from the table.
For example, for the same Fibonacci number, we first calculate fib(0)
then fib(1) then fib(2) then fib(3), and so on.
So literally, we are building the solutions of subproblems bottom-up.
*/


// program Tabulated (bottom up) version
int fibTabulated(int n){
    int f[n+1] = {0};
    f[0] = 0; f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = f[i-1] + f[i-2];
 
    return f[n];
}
