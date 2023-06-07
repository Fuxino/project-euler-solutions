#!/usr/bin/env python3

# The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
#
# Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

from projecteuler import timing


@timing
def p048():
    sum_ = 0

    # Simply calculate the sum of the powers
    for i in range(1, 1001):
        power = i ** i
        sum_ = sum_ + power

    print('Project Euler, Problem 48')
    print(f'Answer: {str(sum_)[-10:]}')


if __name__ == '__main__':
    p048()
