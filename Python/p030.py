#!/usr/bin/env python3

# Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
#
# 1634 = 1^4 + 6^4 + 3^4 + 4^4
# 8208 = 8^4 + 2^4 + 0^4 + 8^4
# 9474 = 9^4 + 4^4 + 7^4 + 4^4
#
# As 1 = 1^4 is not a sum it is not included.
#
# The sum of these numbers is 1634 + 8208 + 9474 = 19316.
#
# Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

from projecteuler import timing


@timing
def p030() -> None:
    tot = 0

    # Straightforward brute force approach. The limit is chosen considering that
    # 6*9^5=354294, so no number larger than that can be expressed as sum
    # of 5th power of its digits.
    for i in range(10, 354295):
        j = i
        _sum = 0

        while j > 0:
            digit = j % 10
            _sum = _sum + digit ** 5
            j = j // 10

        if _sum == i:
            tot = tot + i

    print('Project Euler, Problem 30')
    print(f'Answer: {tot}')


if __name__ == '__main__':
    p030()
