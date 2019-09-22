#!/usr/bin/python3

from timeit import default_timer
from projecteuler import sieve

def is_circular_prime(n):
    global primes

    if primes[n] == 0:
        return False

    tmp = n
    count = 0

    while tmp > 0:
        if tmp % 2 == 0:
            return False
        count = count + 1
        tmp = tmp // 10

    for i in range(1, count):
        n = n % (10 ** (count - 1)) * 10 + n // (10 ** (count - 1))

        if primes[n] == 0:
            return False

    return True

def main():
    start = default_timer()

    global primes

    primes = sieve(1000000)
    count = 13

    for i in range(101, 1000000, 2):
        if is_circular_prime(i):
            count = count + 1

    end = default_timer()

    print('Project Euler, Problem 35')
    print('Answer: {}'.format(count))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
