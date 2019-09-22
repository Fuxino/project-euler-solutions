#!/usr/bin/python3

from numpy import zeros

from timeit import default_timer
from projecteuler import is_pandigital

def main():
    start = default_timer()

    max_ = 0

    for i in range(1, 10000):
        n = 0
        j = 1

        while 1:
            tmp = i * j
            n = n + tmp
            j = j + 1

            if n > max_ and is_pandigital(n, 9):
                max_ = n
            if i * j < 10:
                n = n * 10
            elif i * j < 100:
                n = n * 100
            elif i * j < 1000:
                n = n * 1000
            elif i * j < 10000:
                n = n * 10000
            elif i * j < 100000:
                n = n * 100000

            if n > 987654321:
                break

    end = default_timer()

    print('Project Euler, Problem 38')
    print('Answer: {}'.format(max_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
