#!/usr/bin/env python3

# Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers less than n which are
# relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
#
# n	Relatively Prime    φ(n)    n/φ(n)
# 2	1	            1	    2
# 3	1,2	            2	    1.5
# 4	1,3	            2	    2
# 5	1,2,3,4	            4	    1.25
# 6	1,5	            2	    3
# 7	1,2,3,4,5,6	    6	    1.1666...
# 8	1,3,5,7	            4	    2
# 9	1,2,4,5,7,8	    6	    1.5
# 10	1,3,7,9	            4	    2.5
#
# It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.
#
# Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.

from timeit import default_timer

from projecteuler import is_prime


def main():
    start = default_timer()

    N = 1000000

    i = 1
    res = 1

#   Using Euler's formula, phi(n)=n*prod(1-1/p), where p are the distinct
#   primes that divide n. So n/phi(n)=1/prod(1-1/p). To find the maximum
#   value of this function, the denominator must be minimized. This happens
#   when n has the most distinct small prime factor, i.e. to find the solution
#   we need to multiply the smallest consecutive primes until the result is
#   larger than 1000000.
    while res < N:
        i = i + 1

        if is_prime(i):
            res = res * i

#   We need the previous value, because we want i<1000000
    res = res // i

    end = default_timer()

    print('Project Euler, Problem 69')
    print(f'Answer: {res}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
