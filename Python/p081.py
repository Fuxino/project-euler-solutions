#!/usr/bin/python

# In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down,
# is indicated in bold red and is equal to 2427.
# 
#       *131* 673   234   103    18
#       *201* *96* *342*  965   150
#        630  803  *746* *422*  111
#        537  699   497  *121*  956
#        805  732   524   *37* *331*
#
# Find the minimal path sum, in matrix.txt, a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right
# by only moving right and down.

import sys
from timeit import default_timer


def sum_paths(matrix, m, n):
    for i in range(m-2, -1, -1):
        matrix[m-1][i] = matrix[m-1][i] + matrix[m-1][i+1]
        matrix[i][m-1] = matrix[i][m-1] + matrix[i+1][m-1]

    for i in range(m-2, -1, -1):
        for j in range(n-2, -1, -1):
            if matrix[i][j+1] > matrix[i+1][j]:
                matrix[i][j] = matrix[i][j] + matrix[i+1][j]
            else:
                matrix[i][j] = matrix[i][j] + matrix[i][j+1]

    return matrix[0][0]


def main():
    start = default_timer()

    try:
        with open('matrix.txt', 'r', encoding='utf-8') as fp:
            matrix = fp.readlines()
    except FileNotFoundError:
        print('Error while opening file matrix.txt')
        sys.exit(1)

    j = 0

    for i in matrix:
        matrix[j] = list(map(int, i.strip().split(',')))
        j = j + 1

    dist = sum_paths(matrix, 80, 80)

    end = default_timer()

    print('Project Euler, Problem 81')
    print(f'Answer: {dist}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
