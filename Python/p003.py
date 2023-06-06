#!/usr/bin/env python3

# The prime factors of 13195 are 5, 7, 13 and 29.
#
# What is the largest prime factor of the number 600851475143?

from timeit import default_timer

from projecteuler import is_prime


# Recursive approach: if num is prime, return num, otherwise
# recursively look for the largest prime factor of num divided
# by its prime factors until only the largest remains.
def max_prime_factor(num):
#   Use function defined in projecteuler.py to check if a number is prime.
    if is_prime(num):
        return num

#   If num is even, find the largest prime factor of num/2.
    if num % 2 == 0:
        return max_prime_factor(num // 2)

    i = 3

#   If num is divisible by i and i is prime, find largest
#   prime factor of num/i.
    while True:
        if num % i == 0:
            if is_prime(i):
                return max_prime_factor(num//i)

        i = i + 2

#   Should never get here
    return -1


def main():
    start = default_timer()

    res = max_prime_factor(600851475143)

    end = default_timer()

    print('Project Euler, Problem 3')
    print(f'Answer: {res}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
