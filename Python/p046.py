#!/usr/bin/python3

from timeit import default_timer
from projecteuler import sieve

def goldbach(n):
    global primes

    for i in range(3, n, 2):
        if primes[i] == 1:
            j = 1

            while True:
                tmp = i + 2 * j * j

                if tmp == n:
                    return True

                j = j + 1

                if tmp >= n:
                    break

    return False

def main():
    start = default_timer()

    global primes

    N = 10000

    primes = sieve(N)

    found = 0
    i = 3

    while not found and i < N:
        if primes[i] == 0:
            if not goldbach(i):
                found = 1
        i = i + 2

    end = default_timer()

    print('Project Euler, Problem 46')
    print('Answer: {}'.format(i-2))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
