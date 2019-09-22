#!/usr/bin/python3

from math import sqrt

from timeit import default_timer
from projecteuler import is_pentagonal

def main():
    start = default_timer()

    found = 0
    i = 143

    while not found:
        i = i + 1
        n = i * (2 * i - 1)

        if is_pentagonal(n):
            found = 1

    end = default_timer()

    print('Project Euler, Problem 45')
    print('Answer: {}'.format(n))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
