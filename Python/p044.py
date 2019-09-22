#!/usr/bin/python3

from math import sqrt

from timeit import default_timer
from projecteuler import is_pentagonal

def main():
    start = default_timer()

    found = 0
    n = 2

    while not found:
        pn = n * (3 * n - 1) // 2

        for m in range(1, n):
            pm = m * (3 * m - 1) // 2

            if is_pentagonal(pn+pm) and is_pentagonal(pn-pm):
                found = 1
                break

        n = n + 1

    end = default_timer()

    print('Project Euler, Problem 44')
    print('Answer: {}'.format(pn-pm))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
