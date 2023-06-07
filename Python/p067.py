#!/usr/bin/env python3

# By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
#
#    3
#   7 4
#  2 4 6
# 8 5 9 3
#
# That is, 3 + 7 + 4 + 9 = 23.
# Find the maximum total from top to bottom in p067_triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle
# with one-hundred rows.
#
# NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether!
# If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all.
# There is an efficient algorithm to solve it. ;o)

import sys
from timeit import default_timer

from projecteuler import find_max_path


def main():
    start = default_timer()

    triang = []

    try:
        with open('p067_triangle.txt', 'r', encoding='utf-8') as fp:
            for line in fp:
                triang.append(line.strip('\n').split())
    except FileNotFoundError:
        print('Error while opening file p067_triangle.txt')
        sys.exit(1)

    l = len(triang)

    for i in range(l):
        triang[i] = list(map(int, triang[i]))

#   Use the function implemented in projecteuler.c to find the maximum path.
    max_ = find_max_path(triang, 100)

    end = default_timer()

    print('Project Euler, Problem 67')
    print(f'Answer: {max_}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
