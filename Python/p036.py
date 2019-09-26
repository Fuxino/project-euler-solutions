#!/usr/bin/python3

# The decimal number, 585 = 1001001001_2 (binary), is palindromic in both bases.
#
# Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
#
# (Please note that the palindromic number, in either base, may not include leading zeros.)

from timeit import default_timer
from projecteuler import is_palindrome

def main():
    start = default_timer()

    N = 1000000

    sum_ = 0

#   Brute force approach. For every number below 1 million,
#   check if they're palindrome in base 2 and 10 using the
#   function implemented in projecteuler.c.
    for i in range(1, N):
        if is_palindrome(i, 10) and is_palindrome(i, 2):
            sum_ = sum_ + i

    end = default_timer()

    print('Project Euler, Problem 36')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
