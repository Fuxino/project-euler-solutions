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

    i = 7654321

    while(i > 0):
        if is_pandigital(i, count_digits(i)) and is_prime(i):
            break
        i = i - 2
    
    end = default_timer()

    print('Project Euler, Problem 41')
    print('Answer: {}'.format(i))
    
    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
