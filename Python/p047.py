#!/usr/bin/python3

from timeit import default_timer
from projecteuler import sieve

def count_distinct_factors(n):
    global primes
    count = 0

    if n % 2 == 0:
        count = count + 1

        while True:
            n = n // 2

            if n % 2 != 0:
                break

    i = 3

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
    i = 645

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
