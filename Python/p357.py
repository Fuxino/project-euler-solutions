# Consider the divisors of 30: 1,2,3,5,6,10,15,30.
# It can be seen that for every divisor d of 30, d+30/d is prime.
#
# Find the sum of all positive integers n not exceeding 100 000 000
# such that for every divisor d of n, d+n/d is prime.

from math import floor, sqrt

from projecteuler import sieve, timing


N = 100000000
primes = sieve(N + 2)


def check_d_nd_prime(n):
    limit = floor(sqrt(n))

    for i in range(2, limit + 1):
        if n % i == 0:
            if not primes[i + int(n/i)]:
                return False

    return True


@timing
def p357():
    sum_ = 1

    for i in range(2, N + 1, 2):
        if primes[i + 1] and check_d_nd_prime(i):
            sum_ += i

    print('Project Euler, Problem 357')
    print(f'Answer: {sum_}')


if __name__ == '__main__':
    p357()
