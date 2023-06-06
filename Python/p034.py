#!/usr/bin/env python3

# 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
#
# Find the sum of all numbers which are equal to the sum of the factorial of their digits.
#
# Note: as 1! = 1 and 2! = 2 are not sums they are not included.

from math import factorial
from timeit import default_timer

from numpy import ones


def main():
    start = default_timer()

    a = 10
    sum_ = 0
    factorials = ones(10, int)

#   Pre-calculate factorials of each digit from 0 to 9.
    for i in range(2, 10):
        factorials[i] = factorial(i)

#   9!*7<9999999, so 9999999 is certainly un upper bound.
    while a < 9999999:
        b = a
        sum_f = 0

        while b != 0:
            digit = b % 10
            b = b // 10
            sum_f = sum_f + factorials[digit]

        if a == sum_f:
            sum_ = sum_ + a

        a = a + 1

    end = default_timer()

    print('Project Euler, Problem 34')
    print(f'Answer: {sum_}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
