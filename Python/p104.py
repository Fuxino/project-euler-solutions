#! /usr/bin/env python3

# The Fibonacci sequence is defined by the recurrence relation:
#
# F_n = F_n−1 + F_n−2, where F_1 = 1 and F_2 = 1.
# It turns out that F_541, which contains 113 digits, is the first Fibonacci number for which the last nine digits are 1-9 pandigital
# (contain all the digits 1 to 9, but not necessarily in order). And F_2749, which contains 575 digits, is the first Fibonacci number
# for which the first nine digits are 1-9 pandigital.
#
# Given that F_k is the first Fibonacci number for which the first nine digits AND the last nine digits are 1-9 pandigital, find k.

import sys
from timeit import default_timer

from mpmath import matrix

from projecteuler import is_pandigital


sys.set_int_max_str_digits(70000)


def main():
    start = default_timer()

    found = 0
    fib1 = 1
    fib2 = 1
    i = 2

    while not found:
#       Calculate the next Fibonacci number modulo 10^9 and check if the result is 1-9 pandigital.
        fibn = (fib1 + fib2) % 1000000000
        fib1 = fib2
        fib2 = fibn
        i = i + 1

#       If the last 9 digits of fib_n are pandigital, calculate the ith Fibonacci number using
#       the matrix representation, with sufficient precision so that the at least the first
#       9 digits are correct (we don't need the whole number. If the first 9 digits are also
#       pandigital, we found the solution.
        if is_pandigital(fibn, 9):
            fib_matrix = matrix(2)
            fib_matrix[0, 0] = 1
            fib_matrix[0, 1] = 1
            fib_matrix[1, 0] = 1
            fib_matrix[1, 1] = 0

            fib = fib_matrix ** i
            fib = int(fib[0, 1])

            if is_pandigital(int(str(fib)[:9]), 9):
                found = 1

    end = default_timer()

    print('Project Euler, Problem 104')
    print(f'Answer: {i}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
