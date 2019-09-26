#!/usr/bin/python3

# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
#
# What is the 10 001st prime number?

from timeit import default_timer
from projecteuler import is_prime

def main():
    start = default_timer()

    count = 1
    n = 1

#   Brute force approach: start with count=1 and check every odd number
#   (2 is the only even prime), if it's prime increment count, until the
#   target prime is reached.
    while count != 10001:
        n = n + 2
#       Use the function in projecteuler.py to check if a number is prime.
        if is_prime(n):
            count = count + 1

    end = default_timer()

    print('Project Euler, Problem 7')
    print('Answer: {}'.format(n))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
