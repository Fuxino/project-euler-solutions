#!/usr/bin/env python3

# The decimal number, 585 = 1001001001_2 (binary), is palindromic in both bases.
#
# Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
#
# (Please note that the palindromic number, in either base, may not include leading zeros.)

from projecteuler import is_palindrome, timing


@timing
def p036():
    N = 1000000

    sum_ = 0

    # Brute force approach. For every number below 1 million,
    # check if they're palindrome in base 2 and 10 using the
    # function implemented in projecteuler.c.
    for i in range(1, N):
        if is_palindrome(i, 10) and is_palindrome(i, 2):
            sum_ = sum_ + i

    print('Project Euler, Problem 36')
    print(f'Answer: {sum_}')


if __name__ == '__main__':
    p036()
