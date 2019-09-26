#!/usr/bin/python3

# A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
#
# a2 + b2 = c2
#
# For example, 32 + 42 = 9 + 16 = 25 = 52.
#
# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
#
# Find the product abc.

from timeit import default_timer

def main():
    start = default_timer()

    found = 0

    m = 2

#   Brute force approach: generate all the Pythagorean triplets using
#   Euclid's formula, until the one where a+b+c=1000 is found.
    while not found:
        for n in range(1, m):
            a = m * m - n * n
            b = 2 * m * n
            c = m * m + n * n

            if a + b + c == 1000:
                found = 1
                break

        m = m + 1

    end = default_timer()

    print('Project Euler, Problem 9')
    print('Answer: {}'.format(a * b * c))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
