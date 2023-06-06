#!/usr/bin/env python3

# The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
#
# There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
#
# How many circular primes are there below one million?

from timeit import default_timer

from projecteuler import sieve


# Calculate all primes below one million, then check if they're circular.
N = 1000000
primes = sieve(N)


def is_circular_prime(n):
#   If n is not prime, it's obviously not a circular prime.
    if primes[n] == 0:
        return False

#   The primes below 10 are circular primes.
    if primes[n] == 1 and n < 10:
        return True

    tmp = n
    count = 0

#   If the number has one or more even digits, it can't be a circular prime.
#   because at least one of the rotations will be even.
    while tmp > 0:
        if tmp % 2 == 0:
            return False
#       Count the number of digits.
        count = count + 1
        tmp = tmp // 10

    for _ in range(1, count):
#       Generate rotations and check if they're prime.
        n = n % (10 ** (count - 1)) * 10 + n // (10 ** (count - 1))

        if primes[n] == 0:
            return False

    return True


def main():
    start = default_timer()

    count = 13

#   Calculate all primes below one million, then check if they're circular.
    for i in range(101, N, 2):
        if is_circular_prime(i):
            count = count + 1

    end = default_timer()

    print('Project Euler, Problem 35')
    print(f'Answer: {count}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
