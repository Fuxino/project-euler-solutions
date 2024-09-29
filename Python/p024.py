#!/usr/bin/env python3

# A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
# If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
#
# 012   021   102   120   201   210
#
# What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

from itertools import permutations

from projecteuler import timing


@timing
def p024() -> None:
    # Generate all the permutations in lexicographic order and get the millionth one.
    perm = list(permutations('0123456789'))
    res = int(''.join(map(str, perm[999999])))

    print('Project Euler, Problem 24')
    print(f'Answer: {res}')


if __name__ == '__main__':
    p024()
