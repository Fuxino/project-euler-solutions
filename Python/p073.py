#!/usr/bin/env python3

# Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.
#
# If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:
#
# 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
#
# It can be seen that there are 3 fractions between 1/3 and 1/2.
#
# How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d ≤ 12,000?

from math import gcd
from timeit import default_timer


def main():
    start = default_timer()

    count = 0

#   For each denominator q, we need to find the fractions p/q for which
#   1/3<p/q<1/2. For the lower limit, if p=q/3, then p/q=1/3, so we take
#   p=q/3+1. For the upper limit, if p=q/2 p/q=1/2, so we take p=(q-1)/2.
    for i in range(2, 12001):
        limit = (i - 1) // 2 + 1

        for j in range(i//3+1, limit):
#           Increment the counter if the current fraction is reduced.*/
            if gcd(j, i) == 1:
                count = count + 1

    end = default_timer()

    print('Project Euler, Problem 73')
    print(f'Answer: {count}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
