#!/usr/bin/python3

# Triangle, square, pentagonal, hexagonal, heptagonal, and octagonal numbers are all figurate (polygonal) numbers and are generated
# by the following formulae:
#
# Triangle	 	P3,n=n(n+1)/2	    1, 3, 6, 10, 15, ...
# Square	 	P4,n=n2	 	    1, 4, 9, 16, 25, ...
# Pentagonal	 	P5,n=n(3n−1)/2	    1, 5, 12, 22, 35, ...
# Hexagonal	 	P6,n=n(2n−1)	    1, 6, 15, 28, 45, ...
# Heptagonal	 	P7,n=n(5n−3)/2	    1, 7, 18, 34, 55, ...
# Octagonal	 	P8,n=n(3n−2)	    1, 8, 21, 40, 65, ...
#
# The ordered set of three 4-digit numbers: 8128, 2882, 8281, has three interesting properties.
#
# The set is cyclic, in that the last two digits of each number is the first two digits of the next number (including the last number with the first).
# Each polygonal type: triangle (P3,127=8128), square (P4,91=8281), and pentagonal (P5,44=2882), is represented by a different number in the set.
# This is the only set of 4-digit numbers with this property.
#
# Find the sum of the only ordered set of six cyclic 4-digit numbers for which each polygonal type: triangle, square, pentagonal,
# hexagonal, heptagonal, and octagonal, is represented by a different number in the set.

from numpy import zeros

from timeit import default_timer

# Recursive function to find the required set. It finds a polygonal number,
# check if it can be part of the chain, then use recursion to find the next
# number. If a solution can't be found with the current numbers, it uses
# backtracking and tries the next polygonal number.
def find_set(step):
    global polygonal
    global chain
    global flags
    global sum_

#   Use one polygonal number per type, starting from triangular.
    for i in range(6):
#       If the current type has not been used yet, try it.
        if flags[i] == 0:
#           Set a flag to record that the current polygonal type has been used.
            flags[i] = 1

#           Start from 1010 because numbers finishing with 00, 01, ..., 09 can't
#           be part of the chain.
            for j in range(1010, 10000):
#               If the number doesn't finish with 00, 01, ..., 09 and is poligonal,
#               try adding it to the chain and add its value to the total sum.
                if j % 100 > 9 and polygonal[i, j] == 1:
#                   If it's the first number, just add it as first step in the chain.
                    if step == 0:
                        chain[step] = j
                        sum_ = sum_ + j

#                       Recursively try to add other numbers to the chain. If a solution
#                       is found, return 1.
                        if find_set(step+1):
                            return 1

#                       If a solution was not found, backtrack, subtracting the value of
#                       the number from the total.
                        sum_ = sum_ - j
#                   If this is the last step and the current number can be added to the chain,
#                   add it, update the sum and return 1. A solution has been found.
                    elif step == 5 and j % 100 == chain[0] // 100 and j // 100 == chain[step-1] % 100:
                        chain[step] = j
                        sum_ = sum_ + j
                        return 1
#                   For every other step, add the number to the chain if possible, then recursively
#                   try to add other numbers.
                    elif step < 5 and j // 100 == chain[step-1] % 100:
                        chain[step] = j
                        sum_ = sum_ + j

                        if find_set(step+1):
                            return 1

#                       If a solution was not found, backtrack.
                        sum_ = sum_ - j

#           Remove the flag for the current polygonal type.
            flags[i] = 0

    return 0

def main():
    start = default_timer()

    global polygonal
    global chain
    global flags
    global sum_

    polygonal = zeros((6, 10000), int)
    chain = [0] * 6
    flags = [0] * 6
    sum_ = 0
    i = 1
    n = 1

#   Generate all triangle numbers smaller than 10000
    while True:
        polygonal[0, n] = 1
        i = i + 1
        n = i * (i + 1) // 2

        if n >= 10000:
            break

    i = 1
    n = 1

#   Generate all square numbers smaller than 10000
    while True:
        polygonal[1, n] = 1
        i = i + 1
        n = i * i

        if n >= 10000:
            break

    i = 1
    n = 1

#   Generate all pentagonal numbers smaller than 10000
    while True:
        polygonal[2, n] = 1
        i = i + 1
        n = i * (3 * i - 1) // 2

        if n >= 10000:
            break

    i = 1
    n = 1

#   Generate all hexagonal numbers smaller than 10000
    while True:
        polygonal[3, n] = 1
        i = i + 1
        n = i * (2 * i - 1)

        if n >= 10000:
            break

    i = 1
    n = 1

#   Generate all heptagonal numbers smaller than 10000
    while True:
        polygonal[4, n] = 1
        i = i + 1
        n = i * (5 * i - 3) // 2

        if n >= 10000:
            break

    i = 1
    n = 1
#   Generate all octagonal numbers smaller than 10000
    while True:
        polygonal[5, n] = 1
        i = i + 1
        n = i * (3 * i - 2)

        if n >= 10000:
            break

#   Find the requested set of numbers
    if find_set(0) == 0:
        print('Set not found')

    end = default_timer()

    print('Project Euler, Problem 61')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
