#!/usr/bin/env python3

# A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
#
# Find the largest palindrome made from the product of two 3-digit numbers.

from projecteuler import is_palindrome, timing


@timing
def p004() -> None:
    max_ = 0

    # Using a brute-force approach: generate every product of 3-digit numbers
    # and check if it's palindrome. If the product found is greater than the
    # current maximum, save the current product.
    for i in range(999, 99, -1):
        for j in range(i, 99, -1):
            num = i * j
            # Use the function defined in projecteuler.py to check if a number is palindrome.
            if num > max_ and is_palindrome(num, 10):
                max_ = num

    print('Project Euler, Problem 4')
    print(f'Answer: {max_}')


if __name__ == '__main__':
    p004()
