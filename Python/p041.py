#!/usr/bin/python3

from timeit import default_timer
from projecteuler import is_pandigital, is_prime

def count_digits(n):
    i = 0

    while n > 0:
        i = i + 1
        n = n // 10

    return i

def main():
    start = default_timer()

    for i in range(7654321, 0, -2):
        if is_pandigital(i, count_digits(i)) and is_prime(i):
            print('Project Euler, Problem 41')
            print('Answer: {}'.format(i))
            break

    end = default_timer()

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
