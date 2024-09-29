#!/usr/bin/env python3

# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
#
# Find the sum of all the primes below two million.

from projecteuler import sieve, timing


@timing
def p010() -> None:
    N = 2000000

    # Use the function in projecteuler.py implementing the
    # Sieve of Eratosthenes algorithm to generate primes.
    primes = sieve(N)
    sum_ = 0

    # Sum all the primes
    for i in range(N):
        if primes[i] == 1:
            sum_ = sum_ + i

    print('Project Euler, Problem 10')
    print(f'Answer: {sum_}')


if __name__ == '__main__':
    p010()
