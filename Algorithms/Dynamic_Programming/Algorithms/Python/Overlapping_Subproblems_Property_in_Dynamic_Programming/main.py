"""
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
"""


#  a simple recursive program for Fibonacci numbers
def fib(n):
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)


"""
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
"""

# Memoization (Top Down)
"""
The memoized program for a problem is similar to the recursive version
with a small modification that looks into a lookup table before
computing solutions. We initialize a lookup array with all
initial values as NIL. Whenever we need the solution to a subproblem,
we first look into the lookup table.
If the precomputed value is there then we return that value,
otherwise, we calculate the value and put the result in the lookup table
so that it can be reused later.
"""


# a program for Memoized version of nth Fibonacci number
# function to calculate nth Fibonacci number
def fibMemorized(n, lookup):
    # base case
    if n <= 1:
        lookup[n] = n

    # if the value is not calculated previously then calculate it
    if lookup[n] is None:
        lookup[n] = fibMemorized(n-1, lookup) + fib(n-2, lookup)

    # return the value corresponding to that value of n
    return lookup[n]
# end of function


# Driver program to test the above function
def main1():
    n = 34
    # Declaration of lookup table
    # Handles till n = 100
    lookup = [None] * 101
    print(f"Fibonacci Number is {fibMemorized(n, lookup)}")


# Tabulation (Bottom Up)
"""
The tabulated program for a given problem builds a table in bottom-up fashion
and returns the last entry from the table.
For example, for the same Fibonacci number, we first calculate fib(0)
then fib(1) then fib(2) then fib(3), and so on.
So literally, we are building the solutions of subproblems bottom-up.
"""


# Python program Tabulated (bottom up) version
def fibTabulated(n):
    # array declaration
    f = [0] * (n + 1)
    # base case assignment
    f[1] = 1
    # calculating the fibonacci and storing the values
    for i in range(2, n + 1):
        f[i] = f[i - 1] + f[i - 2]
    return f[n]


# Driver program to test the above function
def main2():
    n = 9
    print(f"Fibonacci number is {fibTabulated(n)}")


if __name__ == "__main__":
    main1()
    main2()
