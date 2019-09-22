#!/usr/bin/python3

from timeit import default_timer
from projecteuler import sieve

def main():
    start = default_timer()

    N = 1000000

    primes = sieve(N)

    max_ = 0
    max_p = 0

    for i in range(2, N):
        if primes[i] == 1:
            count = 1
            sum_ = i
            j = i + 1

            while j < N and sum_ < N:
                if primes[j] == 1:
                    sum_ = sum_ + j
                    count = count + 1

                    if sum_ < N and primes[sum_] == 1 and count > max_:
                        max_ = count
                        max_p = sum_

                j = j + 1

    end = default_timer()

    print('Project Euler, Problem 50')
    print('Answer: {}'.format(max_p))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
