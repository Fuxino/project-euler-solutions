#!/usr/bin/python3

from timeit import default_timer
from projecteuler import sieve

def main():
    start = default_timer()

    N = 2000000

    primes = sieve(N)
    sum_ = 0

    for i in range(N):
        if primes[i] == 1:
            sum_ = sum_ + i

    end = default_timer()

    print('Project Euler, Problem 10')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
