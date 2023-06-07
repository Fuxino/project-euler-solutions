#!/usr/bin/env python3

# A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
#
# a2 + b2 = c2
#
# For example, 32 + 42 = 9 + 16 = 25 = 52.
#
# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
#
# Find the product abc.

from math import gcd
from projecteuler import timing


@timing
def p009():
    found = 0

    m = 2

    # Brute force approach: generate all the Pythagorean triplets using
    # Euclid's formula, until the one where a+b+c=1000 is found.
    while not found:
        for n in range(1, m):
            if found == 1:
                break

            if gcd(m, n) == 1 and (m % 2 == 0 and n % 2 != 0 or m % 2 != 0 and n % 2 == 0):
                a = m * m - n * n
                b = 2 * m * n
                c = m * m + n * n

                if a + b + c == 1000:
                    found = 1
                    break

                i = 2

                while True:
                    tmpa = a * i
                    tmpb = b * i
                    tmpc = c * i

                    if tmpa + tmpb + tmpc == 1000:
                        a = tmpa
                        b = tmpb
                        c = tmpc
                        found = 1
                        break

                    if tmpa + tmpb + tmpc > 1000:
                        break

                    i = i + 1

        m = m + 1

    print('Project Euler, Problem 9')
    print(f'Answer: {a * b * c}')


if __name__ == '__main__':
    p009()
