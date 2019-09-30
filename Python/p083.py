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

from numpy import zeros

from timeit import default_timer
from projecteuler import dijkstra

def main():
    start = default_timer()

    try:
        fp = open('matrix.txt', 'r')
    except:
        print('Error while opening file {}'.format('matrix.txt'))
        exit(1)

    matrix = fp.readlines()
    distances = zeros((80, 80), int)

    j = 0
    for i in matrix:
        matrix[j] = list(map(int, i.strip().split(',')))
        j = j + 1

    dijkstra(matrix, distances, 80, 80, 1, 1) 

    dist = distances[79][79]

    end = default_timer()

    print('Project Euler, Problem 83')
    print('Answer: {}'.format(dist))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
