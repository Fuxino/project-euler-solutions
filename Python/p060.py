#!/usr/bin/python

# The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime.
# For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes
# with this property.
#
# Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.

from timeit import default_timer
from projecteuler import sieve, is_prime

def main():
    start = default_timer()

    N = 10000

    primes = sieve(N)

    found = 0
    p1 = 3

#   Straightforward brute force approach
    while p1 < N and not found:
#       If p1 is not prime, go to the next number.
        if primes[p1] == 0:
            p1 = p1 + 2
            continue

        p2 = p1 + 2

        while p2 < N and not found:
#           If p2 is not prime, or at least one of the possible concatenations of 
#           p1 and p2 is not prime, go to the next number.
            if primes[p2] == 0 or not is_prime(int(str(p1)+str(p2))) or not is_prime(int(str(p2)+str(p1))):
                p2 = p2 + 2
                continue

            p3 = p2 + 2

            while p3 < N and not found:
#               If p3 is not prime, or at least one of the possible concatenations of
#               p1, p2 and p3 is not prime, got to the next number.
                if primes[p3] == 0 or not is_prime(int(str(p1)+str(p3))) or not is_prime(int(str(p3)+str(p1))) or\
                        not is_prime(int(str(p2)+str(p3))) or not is_prime(int(str(p3)+str(p2))):
                            p3 = p3 + 2
                            continue

                p4 = p3 + 2

                while p4 < N and not found:
#                   If p4 is not prime, or at least one of the possible concatenations of
#                   p1, p2, p3 and p4 is not prime, go to the next number.
                    if primes[p4] == 0 or not is_prime(int(str(p1)+str(p4))) or not is_prime(int(str(p4)+str(p1))) or\
                            not is_prime(int(str(p2)+str(p4))) or not is_prime(int(str(p4)+str(p2))) or\
                            not is_prime(int(str(p3)+str(p4))) or not is_prime(int(str(p4)+str(p3))):
                                p4 = p4 + 2
                                continue

                    p5 = p4 + 2

                    while p5 < N and not found:
#                       If p5 is not prime, or at least one of the possible concatenations of
#                       p1, p2, p3, p4 and p5 is not prime, go to the next number
                        if primes[p5] == 0 or not is_prime(int(str(p1)+str(p5))) or not is_prime(int(str(p5)+str(p1))) or\
                                not is_prime(int(str(p2)+str(p5))) or not is_prime(int(str(p5)+str(p2))) or\
                                not is_prime(int(str(p3)+str(p5))) or not is_prime(int(str(p5)+str(p3))) or\
                                not is_prime(int(str(p4)+str(p5))) or not is_prime(int(str(p5)+str(p4))):
                                    p5 = p5 + 2
                                    continue

#                       If it gets here, the five values have been found.
                        n = p1 + p2 + p3 + p4 + p5
                        found = 1

                    p4 = p4 + 2

                p3 = p3 + 2

            p2 = p2 + 2

        p1 = p1 + 2

    end = default_timer()

    print('Project Euler, Problem 59')
    print('Answer: {}'.format(n))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
