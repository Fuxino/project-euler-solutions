#!/usr/bin/python

# It is possible to write ten as the sum of primes in exactly five different ways:
#
# 7 + 3
# 5 + 5
# 5 + 3 + 2
# 3 + 3 + 2 + 2
# 2 + 2 + 2 + 2 + 2
#
# What is the first value which can be written as the sum of primes in over five thousand different ways?

from projecteuler import is_prime, timing


primes = [0] * 100


# Function using a simple recursive brute force approach to find all the partitions.
def count(value, n, i, target):
    for j in range(i, 100):
        value = value + primes[j]

        if value == target:
            return n + 1

        if value > target:
            return n

        n = count(value, n, j, target)
        value = value - primes[j]

    return n


@timing
def p077():
    # Generate a list of the first 100 primes.
    i = 0
    j = 0

    while j < 100:
        if is_prime(i):
            primes[j] = i
            j = j + 1
        i = i + 1

    i = 2

    # Use a function to count the number of prime partitions for
    # each number >= 2 until the one that can be written in over
    # 5000 ways is found.
    while True:
        n = count(0, 0, 0, i)

        if n > 5000:
            break

        i = i + 1

    print('Project Euler, Problem 77')
    print(f'Answer: {i}')


if __name__ == '__main__':
    p077()
