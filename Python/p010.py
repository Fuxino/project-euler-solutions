#!/usr/bin/python3

# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
#
# Find the sum of all the primes below two million.

from timeit import default_timer
from projecteuler import sieve

def main():
    start = default_timer()

    N = 2000000

#   Use the function in projecteuler.py implementing the 
#   Sieve of Eratosthenes algorithm to generate primes.
    primes = sieve(N)
    sum_ = 0

#   Sum all the primes
    for i in range(N):
        if primes[i] == 1:
            sum_ = sum_ + i

    end = default_timer()

    print('Project Euler, Problem 10')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
