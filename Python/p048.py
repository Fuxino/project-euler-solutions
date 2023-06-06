#!/usr/bin/env python3

# The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
#
# Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

from timeit import default_timer


def main():
    start = default_timer()

    sum_ = 0

#   Simply calculate the sum of the powers
    for i in range(1, 1001):
        power = i ** i
        sum_ = sum_ + power

    end = default_timer()

    print('Project Euler, Problem 48')
    print(f'Answer: {str(sum_)[-10:]}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
