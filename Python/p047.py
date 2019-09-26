#!/usr/bin/python3

# The first two consecutive numbers to have two distinct prime factors are:
#
# 14 = 2 × 7
# 15 = 3 × 5
#
# The first three consecutive numbers to have three distinct prime factors are:
#
# 644 = 2² × 7 × 23
# 645 = 3 × 5 × 43
# 646 = 2 × 17 × 19.
#
# Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?

from timeit import default_timer
from projecteuler import sieve

def count_distinct_factors(n):
    global primes
    count = 0

#   Start checking if 2 is a prime factor of n. Then remove
#   all 2s factore.
    if n % 2 == 0:
        count = count + 1

        while True:
            n = n // 2

            if n % 2 != 0:
                break

    i = 3

#   Check all odd numbers i, if they're prime and they're a factor
#   of n, count them and then divide n for by i until all factors i
#   are eliminated. Stop the loop when n=1, i.e. all factors have
#   been found.
    while n > 1:
        if primes[i] == 1 and n % i == 0:
            count = count + 1

            while True:
                n = n // i

                if n % i != 0:
                    break
        i = i + 2

    return count

def main():
    start = default_timer()

    global primes

    N = 150000

    primes = sieve(N)
    found = 0
    i = 647

#   Starting from 647, count the distinct prime factors of n, n+1, n+2 and n+3.
#   If they all have 4, the solution is found.
    while not found and i < N - 3:
        if primes[i] == 0 and primes[i+1] == 0 and primes[i+2] == 0 and primes[i+3] == 0:
            if count_distinct_factors(i) == 4 and count_distinct_factors(i+1) == 4 and count_distinct_factors(i+2) == 4 and count_distinct_factors(i+3) == 4:
                found = 1
        i  = i + 1

    end = default_timer()

    print('Project Euler, Problem 47')
    print('Answer: {}'.format(i-1))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
