#!/usr/bin/python3

# Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.
#
# If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:
#
# 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
#
# It can be seen that 2/5 is the fraction immediately to the left of 3/7.
#
# By listing the set of reduced proper fractions for d ≤ 1,000,000 in ascending order of size, find the numerator
# of the fraction immediately to the left of 3/7.

from math import gcd

from timeit import default_timer

def main():
    start = default_timer()

    N = 1000000

    max_ = 0

#   For each denominator q, we need to find the biggest numerator p for which
#   p/q<a/b, where a/b is 3/7 for this problem. So:
#   pb<aq
#   pb<=aq-1
#   p<=(aq-1)/b
#   So we can set p=(3*q-1)/7 (using integer division).
    for i in range(2, N+1):
        j = (3 * i - 1) // 7

        if j / i > max_:
            n = j
            d = i
            max_ = n / d

#           Reduce the fractions if it's not already reduced.
            if gcd(i, j) > 1:
                n /= gcd(i, j)
                d /= gcd(i, j)

            max_n = n

    end = default_timer()

    print('Project Euler, Problem 71')
    print('Answer: {}'.format(max_n))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
