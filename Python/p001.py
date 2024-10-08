#!/usr/bin/env python3

# If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
#
# Find the sum of all the multiples of 3 or 5 below 1000.

from projecteuler import timing


@timing
def p001() -> None:
    _sum = 0

    # Simple brute-force approach: try every number between 3 and 999,
    # check if it's a multiple of 3 or 5, if yes add it to the total.
    for i in range(3, 1000):
        if i % 3 == 0 or i % 5 == 0:
            _sum += i

    print('Project Euler, Problem 1')
    print(f'Answer: {_sum}')


if __name__ == '__main__':
    p001()
