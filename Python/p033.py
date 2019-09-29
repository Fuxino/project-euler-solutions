#!/usr/bin/python3

# The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8,
# which is correct, is obtained by cancelling the 9s.
#
# We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
#
# There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator
# and denominator.
#
# If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

from math import gcd

from timeit import default_timer

def main():
    start = default_timer()

    prod_n = 1
    prod_d = 1

    for i in range(11, 100):
        for j in range(11, 100):
#           If the example is non-trivial, check if cancelling the digit that's equal
#           in numerator and denominator gives the same fraction.
            if i % 10 != 0 and j % 10 != 0 and\
            i != j and i % 10 == j // 10:
                n = i // 10
                d = j % 10

                f1 = i / j
                f2 = n / d

                if f1 == f2:
                    prod_n = prod_n * i
                    prod_d = prod_d * j

#   Find the greater common divisor of the fraction found.
    div = gcd(prod_n, prod_d)

    end = default_timer()

    print('Project Euler, Problem 33')
    print('Answer: {}'.format(prod_d // div))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
