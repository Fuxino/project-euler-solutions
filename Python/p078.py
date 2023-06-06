#!/usr/bin/python

# Let p(n) represent the number of different ways in which n coins can be separated into piles.
# For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.
#
#   OOOOO
#   OOOO  O
#   OOO  OO
#   OOO  O  O
#   OO  OO  O
#   OO  O  O  O
#   O  O  O  O  O
#
# Find the least value of n for which p(n) is divisible by one million.

from timeit import default_timer

from projecteuler import partition_fn


def main():
    start = default_timer()

    N = 1000000

    partitions = [0] * N

    i = 0

#   Using the partition function to calculate the number of partitions,
#   giving the result modulo N.*/
    while partition_fn(i, partitions, N) != 0:
        i = i + 1

    end = default_timer()

    print('Project Euler, Problem 78')
    print(f'Answer: {i}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
