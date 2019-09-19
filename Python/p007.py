#!/usr/bin/python3

from timeit import default_timer
from projecteuler import is_prime

def main():
    start = default_timer()

    count = 1
    n = 1

    while count != 10001:
        n = n + 2

        if is_prime(n):
            count = count + 1

    end = default_timer()

    print('Project Euler, Problem 7')
    print('Answer: {}'.format(n))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
