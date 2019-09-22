#!/usr/bin/python3

from numpy import zeros

from timeit import default_timer
from projecteuler import sieve

def check_digits(a, b):
    digits1 = zeros(10, int)
    digits2 = zeros(10, int)

    while a > 0:
        digits1[a%10] = digits1[a%10] + 1
        a = a // 10

    while b > 0:
        digits2[b%10] = digits2[b%10] + 1
        b = b // 10

    for i in range(10):
        if digits1[i] != digits2[i]:
            return False

    return True

def main():
    start = default_timer()

    N = 10000

    primes = sieve(N)

    found = 0
    i = 1489

    while i < N and found == 0:
        if primes[i] == 1:
            for j in range(1, 4255):
                if i + 2 * j < N and primes[i+j] == 1 and primes[i+2*j] == 1 and\
                        check_digits(i, i+j) and check_digits(i, i+2*j):
                            found = 1
                            break
        i = i + 1

    end = default_timer()

    print('Project Euler, Problem 49')
    print('Answer: {}'.format(str(i-1)+str(i-1+j)+str(i-1+2*j)))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
