#!/usr/bin/python3

from timeit import default_timer
from projecteuler import partition_fn

def main():
    start = default_timer()

    partitions = [0] * 101

#   The number of ways a number can be written as a sum is given by the partition function
#   (-1 because the partition function includes also the number itself).
#   The function is implemented in projecteuler.py.
    n = partition_fn(100, partitions) - 1

    end = default_timer()

    print('Project Euler, Problem 76')
    print('Answer: {}'.format(n))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
