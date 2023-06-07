#!/usr/bin/env python3

# The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right,
# and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
#
# Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
#
# NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

from projecteuler import is_prime, timing


def is_tr_prime(n):
    # One-digit numbers and non-prime numbers are
    # not truncatable primes.
    if n < 11 or not is_prime(n):
        return False

    tmp = n // 10

    # Remove one digit at a time from the right and check
    # if the resulting number is prime. Return 0 if it isn't.
    while tmp > 0:
        if not is_prime(tmp):
            return False
        tmp = tmp // 10

    # Starting from the last digit, check if it's prime, then add back one digit at a time on the left and check if it
    # is prime. Return 0 when it isn't.
    i = 10
    tmp = n % i

    while tmp != n:
        if not is_prime(tmp):
            return False
        i = i * 10
        tmp = n % i

    # If it gets here, the number is truncatable prime.
    return True


@timing
def p037():
    i = 0
    n = 1
    sum_ = 0

    # Check every number until 11 truncatable primes are found.
    while i < 11:
        if is_tr_prime(n):
            sum_ = sum_ + n
            i = i + 1
        n = n + 1

    print('Project Euler, Problem 37')
    print(f'Answer: {sum_}')


if __name__ == '__main__':
    p037()
