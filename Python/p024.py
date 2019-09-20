#!/usr/bin/python3

from itertools import permutations

from timeit import default_timer

def main():
    start = default_timer()

    perm = list(permutations('0123456789'))
    res = int(''.join(map(str, perm[999999])))

    end = default_timer()

    print('Project Euler, Problem 24')
    print('Answer: {}'.format(res))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
