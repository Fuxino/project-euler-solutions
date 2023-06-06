#!/usr/bin/env python3

# 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
#
# What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

from timeit import default_timer
from projecteuler import lcmm


def main():
    start = default_timer()

    values = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
              11, 12, 13, 14, 15, 16, 17, 18, 19, 20)

#   Function define in projecteuler.py to find the least common multiple of multiple numbers.
    res = lcmm(values, 20)

    end = default_timer()

    print('Project Euler, Problem 5')
    print(f'Answer: {res}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
