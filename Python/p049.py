#!/usr/bin/env python3

# The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime,
# and, (ii) each of the 4-digit numbers are permutations of one another.
#
# There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit
# increasing sequence.
#
# What 12-digit number do you form by concatenating the three terms in this sequence?

from projecteuler import sieve, timing


@timing
def p049():
    N = 10000

    primes = sieve(N)

    found = 0
    i = 1489

    # Starting from i=1489 (bigger than the first number in the sequence given in the problem),
    # check odd numbers. If they're prime, loop on even numbers j (odd+even=odd, odd+odd=even and
    # we need odd numbers because we're looking for primes) up to 4254 (1489+2*4256=10001 which has
    # 5 digits.
    while i < N:
        if primes[i] == 1:
            for j in range(1, 4255):
                # If i, i+j and i+2*j are all primes and they have all the same digits, the result has been found.
                if i + 2 * j < N and primes[i+j] == 1 and primes[i+2*j] == 1 and\
                        ''.join(sorted(str(i))) == ''.join(sorted(str(i+j))) and\
                        ''.join(sorted(str(i))) == ''.join(sorted(str(i+2*j))):
                    found = 1
                    break
        if found:
            break

        i = i + 2

    print('Project Euler, Problem 49')
    print(f'Answer: {str(i)+str(i+j)+str(i+2*j)}')


if __name__ == '__main__':
    p049()
