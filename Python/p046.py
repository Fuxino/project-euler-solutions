#!/usr/bin/env python3

# It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
#
# 9 = 7 + 2×1^2
# 15 = 7 + 2×2^2
# 21 = 3 + 2×3^2
# 25 = 7 + 2×3^2
# 27 = 19 + 2×2^2
# 33 = 31 + 2×1^2
#
# It turns out that the conjecture was false.
#
# What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

from timeit import default_timer

from projecteuler import sieve


N = 10000
primes = sieve(N)


def goldbach(n):
#   Check every prime smaller than n.
    for i in range(3, n, 2):
        if primes[i] == 1:
            j = 1

#           Check if summing twice a square to the prime number
#           gives n. Return 1 when succeeding.
            while True:
                tmp = i + 2 * j * j

                if tmp == n:
                    return True

                j = j + 1

                if tmp >= n:
                    break

#   Return 0 if no solution is found.
    return False

def main():
    start = default_timer()

    found = 0
    i = 3

#   For every odd number, check if it's prime, if it is check
#   if it satisfies the Goldbach property. Continue until the
#   first number that doesn't is found.
    while not found and i < N:
        if primes[i] == 0:
            if not goldbach(i):
                found = 1
        i = i + 2

    end = default_timer()

    print('Project Euler, Problem 46')
    print(f'Answer: {i - 2}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
