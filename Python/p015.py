#!/usr/bin/python3

from math import factorial

from timeit import default_timer

def main():
    start = default_timer()

    count = factorial(40)
    tmp = factorial(20)
    tmp = tmp * tmp
    count = count // tmp

    end = default_timer()

    print('Project Euler, Problem 15')
    print('Answer: {}'.format(count))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
