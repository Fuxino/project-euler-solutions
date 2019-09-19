#!/usr/bin/python3

from timeit import default_timer
from projecteuler import count_divisors

def main():
    start = default_timer()

    i = 0
    triang = 0
    finished = 0

    while not finished:
        i = i + 1
        triang = triang + i

        if count_divisors(triang) > 500:
            finished = 1

    end = default_timer()

    print('Project Euler, Problem 12')
    print('Answer: {}'.format(triang))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
