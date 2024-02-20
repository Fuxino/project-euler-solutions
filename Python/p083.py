#!/usr/bin/python

# NOTE: This problem is a significantly more challenging version of Problem 81.
#
# In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by moving left, right, up, and down,
# is indicated in bold red and is equal to 2297.
#
#       *131* 673  *234* *103*  *18*
#       *201* *96* *342*  965  *150*
#        630  803   746  *422* *111*
#        537  699   497  *121*  956
#        805  732   524   *37* *331*
#
# Find the minimal path sum, in matrix.txt, a 31K text file containing a 80 by 80 matrix,
# from the top left to the bottom right by moving left, right, up, and down.

import sys

from numpy import zeros

from projecteuler import dijkstra, timing


@timing
def p083():
    try:
        with open('matrix.txt', 'r', encoding='utf-8') as fp:
            matrix = fp.readlines()
    except FileNotFoundError:
        print('Error while opening file matrix.txt')
        sys.exit(1)

    distances = zeros((80, 80), int)

    j = 0
    for i in matrix:
        matrix[j] = list(map(int, i.strip().split(',')))
        j = j + 1

    dijkstra(matrix, distances, 80, 80, 1, 1)

    dist = distances[79][79]

    print('Project Euler, Problem 83')
    print(f'Answer: {dist}')


if __name__ == '__main__':
    p083()
