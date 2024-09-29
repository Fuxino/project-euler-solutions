#!/usr/bin/env python3

# Euler discovered the remarkable quadratic formula:
#
# n^2+n+41
#
# It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39. However, when n=40,402+40+41=40(40+1)+41 is
# divisible by 41, and certainly when n=41,412+41+41 is clearly divisible by 41.
#
# The incredible formula n^2−79n+1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤79.
# The product of the coefficients, −79 and 1601, is −126479.
#
# Considering quadratics of the form:
#
# n^2+an+b, where |a|<1000 and |b|≤1000
#
# where |n| is the modulus/absolute value of n
# e.g. |11|=11 and |−4|=4
#
# Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n,
# starting with n=0.

from projecteuler import is_prime, timing


@timing
def p027() -> None:
    _max = 0

    # Brute force approach, optimized by checking only values of b where b is prime.
    for a in range(-999, 1000):
        for b in range(2, 1001):
            # For n=0, n^2+an+b=b, so b must be prime.
            if is_prime(b):
                n = 0
                count = 0

                while True:
                    p = n * n + a * n + b

                    if p > 1 and is_prime(p):
                        count = count + 1
                        n = n + 1
                    else:
                        break

                if count > _max:
                    _max = count
                    save_a = a
                    save_b = b

    print('Project Euler, Problem 27')
    print(f'Answer: {save_a * save_b}')


if __name__ == '__main__':
    p027()
