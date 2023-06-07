#!/usr/bin/env python3

# The prime 41, can be written as the sum of six consecutive primes:
#
# 41 = 2 + 3 + 5 + 7 + 11 + 13
#
# This is the longest sum of consecutive primes that adds to a prime below one-hundred.
#
# The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
#
# Which prime, below one-million, can be written as the sum of the most consecutive primes?

from projecteuler import sieve, timing


@timing
def p050():
    N = 1000000

    primes = sieve(N)

    max_ = 0
    max_p = 0

    # Starting from a prime i, add consecutive primes until the
    # sum exceeds the limit, every time the sum is also a prime
    # save the value and the count if the count is larger than the
    # current maximum. Repeat for all primes below N.
    # A separate loop is used for i=2, so later only odd numbers are
    # checked for primality.
    i = 2
    j = i + 1
    count = 1
    sum_ = i

    while j < N and sum_ < N:
        if primes[j] == 1:
            sum_ = sum_ + j
            count = count + 1

            if sum_ < N and primes[sum_] == 1 and count > max_:
                max_ = count
                max_p = sum
        j = j + 1

    for i in range(3, N, 2):
        if primes[i] == 1:
            count = 1
            sum_ = i
            j = i + 2

            while j < N and sum_ < N:
                if primes[j] == 1:
                    sum_ = sum_ + j
                    count = count + 1

                    if sum_ < N and primes[sum_] == 1 and count > max_:
                        max_ = count
                        max_p = sum_

                j = j + 2

    print('Project Euler, Problem 50')
    print(f'Answer: {max_p}')


if __name__ == '__main__':
    p050()
