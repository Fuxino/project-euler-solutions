#!/usr/bin/python3

# The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime,
# and, (ii) each of the 4-digit numbers are permutations of one another.
#
# There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit
# increasing sequence.
#
# What 12-digit number do you form by concatenating the three terms in this sequence?

from numpy import zeros

from timeit import default_timer
from projecteuler import sieve

def check_digits(a, b):
    digits1 = zeros(10, int)
    digits2 = zeros(10, int)

    while a > 0:
        digits1[a%10] = digits1[a%10] + 1
        a = a // 10

    while b > 0:
        digits2[b%10] = digits2[b%10] + 1
        b = b // 10

    for i in range(10):
        if digits1[i] != digits2[i]:
            return False

    return True

def main():
    start = default_timer()

    N = 10000

    primes = sieve(N)

    found = 0
    i = 1489

#   Starting from i=1489 (bigger than the first number in the sequence given in the problem),
#   check odd numbers. If they're prime, loop on even numbers j (odd+even=odd, odd+odd=even and
#   we need odd numbers because we're looking for primes) up to 4254 (1489+2*4256=10001 which has
#   5 digits.
    while i < N:
        if primes[i] == 1:
            for j in range(1, 4255):
#               If i, i+j and i+2*j are all primes and they have
#               all the same digits, the result has been found.
                if i + 2 * j < N and primes[i+j] == 1 and primes[i+2*j] == 1 and\
                        check_digits(i, i+j) and check_digits(i, i+2*j):
                            found = 1
                            break
        if(found):
            break
        i = i + 2

    end = default_timer()

    print('Project Euler, Problem 49')
    print('Answer: {}'.format(str(i)+str(i+j)+str(i+2*j)))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
