#!/usr/bin/env python3

# The sum of the squares of the first ten natural numbers is,
#
# 1^2 + 2^2 + ... + 10^2 = 385
#
# The square of the sum of the first ten natural numbers is,
#
# (1 + 2 + ... + 10)^2 = 55^2 = 3025
#
# Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
#
# Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

from projecteuler import timing


@timing
def p006() -> None:
    sum_squares = 0
    square_sum = 0

    # Straightforward brute-force approach.
    for i in range(1, 101):
        sum_squares = sum_squares + i * i
        square_sum = square_sum + i

    square_sum = square_sum * square_sum

    print('Project Euler, Problem 6')
    print(f'Answer: {square_sum - sum_squares}')


if __name__ == '__main__':
    p006()
