#!/usr/bin/python3

from timeit import default_timer
from projecteuler import lcmm

def main():
    start = default_timer()

    values = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
              11, 12, 13, 14, 15, 16, 17, 18, 19, 20)

    res = lcmm(values, 20)

    end = default_timer()

    print('Project Euler, Problem 5')
    print('Answer: {}'.format(res))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
