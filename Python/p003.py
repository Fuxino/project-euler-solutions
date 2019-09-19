#!/usr/bin/python3

import math

from timeit import default_timer
from projecteuler import is_prime

def max_prime_factor(num):
    if is_prime(num):
        return num

    if num % 2 == 0:
        return max_prime_factor(num / 2)

    else:
        limit = math.floor(math.sqrt(num)) + 1

        for i in range(3, limit, 2):
            if num % i == 0:
                if is_prime(i):
                    return max_prime_factor(num / i)

def main():
    start = default_timer()

    res = max_prime_factor(600851475143)

    end = default_timer()

    print('Project Euler, Problem 3')
    print('Answer: {}'.format(int(res)))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
