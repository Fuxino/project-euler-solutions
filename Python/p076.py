#!/usr/bin/env python3

# It is possible to write five as a sum in exactly six different ways:
#
# 4 + 1
# 3 + 2
# 3 + 1 + 1
# 2 + 2 + 1
# 2 + 1 + 1 + 1
# 1 + 1 + 1 + 1 + 1
#
# How many different ways can one hundred be written as a sum of at least two positive integers?*/

from projecteuler import partition_fn, timing


@timing
def p076():
    partitions = [0] * 101

    # The number of ways a number can be written as a sum is given by the partition function
    # (-1 because the partition function includes also the number itself).
    # The function is implemented in projecteuler.py.
    n = partition_fn(100, partitions) - 1

    print('Project Euler, Problem 76')
    print(f'Answer: {n}')


if __name__ == '__main__':
    p076()
