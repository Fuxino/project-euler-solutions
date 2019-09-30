#!/usr/bin/python

# NOTE: THIS SOLUTION WORKS, BUT IT'S EXTREMELY SLOW. THE C VERSION RUNS IN A FEW SECONDS, THIS ONE TAKES SEVERAL MINUTES.
#
# NOTE: This problem is a more challenging version of Problem 81.
#
# The minimal path sum in the 5 by 5 matrix below, by starting in any cell in the left column and finishing in any cell in the right column,
# and only moving up, down, and right, is indicated in red and bold; the sum is equal to 994.
#
#        131  673  *234* *103*  *18*
#       *201* *96* *342*  965   150
#        630  803   746   422   111
#        537  699   497   121   956
#        805  732   524    37   331 
#
# Find the minimal path sum, in matrix.txt, a 31K text file containing a 80 by 80 matrix, from the left column to the right column.

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

    min_path = 999999999

#   Use Dijkstra's algorithm starting from all possible nodes
#   in the first column.
    for i in range(80):
        dijkstra(matrix, distances, 80, 80, 1, 0, i)

#       For the current starting node, check if there is an ending node
#       with a smaller path cost than the current minimum.
        for j in range(80):
            if distances[j][79] < min_path:
                min_path = distances[j][79]

    end = default_timer()

    print('Project Euler, Problem 82')
    print('Answer: {}'.format(min_path))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
