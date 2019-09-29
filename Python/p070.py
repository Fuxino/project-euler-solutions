#!/usr/bin/python3

# Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of positive numbers
# less than or equal to n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and
# relatively prime to nine, φ(9)=6.
# The number 1 is considered to be relatively prime to every positive number, so φ(1)=1.
#
# Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.
#
# Find the value of n, 1 < n < 10^7, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.

from numpy import zeros

from timeit import default_timer
from projecteuler import sieve, is_semiprime, phi_semiprime

def main():
    start = default_timer()

    N = 10000000
    n = -1
    min_ = float('inf')
    semi_p = False

    primes = sieve(N)

    for i in range(2, N):
#       When n is prime, phi(n)=(n-1), so to minimize n/phi(n) we should
#       use n prime. But n-1 can't be a permutation of n. The second best 
#       bet is to use semiprimes. For a semiprime n=p*q, phi(n)=(p-1)(q-1).
#       So we check if a number is semiprime, if yes calculate phi, finally
#       check if phi(n) is a permutation of n and update the minimum if it's
#       smaller.
        semi_p, a, b = is_semiprime(i, primes)
        
        if semi_p == True:
            p = phi_semiprime(i, a, b)

            if ''.join(sorted(str(p))) == ''.join(sorted(str(i))) and i / p < min_:
                n = i
                min_ = i / p

    end = default_timer()

    print('Project Euler, Problem 70')
    print('Answer: {}'.format(n))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
