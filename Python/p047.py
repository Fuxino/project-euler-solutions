#!/usr/bin/python3

# The first two consecutive numbers to have two distinct prime factors are:
#
# 14 = 2 × 7
# 15 = 3 × 5
#
# The first three consecutive numbers to have three distinct prime factors are:
#
# 644 = 2² × 7 × 23
# 645 = 3 × 5 × 43
# 646 = 2 × 17 × 19.
#
# Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?

from timeit import default_timer

# Function using a modified sieve of Eratosthenes to count
# the distinct prime factors of each number.
def count_factors(n):
    factors = [0] * n
    i = 2

    while i < n // 2:
        if factors[i] == 0:
            for j in range(i, n, i):
                factors[j] = factors[j] + 1
        i = i + 1

    return factors

def main():
    start = default_timer()

    N = 150000

    factors = count_factors(N)

    count = 0

#   Find the first instance of four consecutive numbers
#   having four distinct prime factors.
    for i in range(N):
        if factors[i] == 4:
            count = count + 1
        else:
            count = 0

        if count == 4:
            res = i - 3
            break

    end = default_timer()

    print('Project Euler, Problem 47')
    print('Answer: {}'.format(res))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
