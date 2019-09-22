#!/usr/bin/python3

from itertools import permutations

from timeit import default_timer

def has_property(n):
    value = int(n[1]) * 100 + int(n[2]) * 10 + int(n[3])

    if value % 2 != 0:
        return False

    value = int(n[2]) * 100 + int(n[3]) * 10 + int(n[4])

    if value % 3 != 0:
        return False

    value = int(n[3]) * 100 + int(n[4]) * 10 + int(n[5])

    if value % 5 != 0:
        return False

    value = int(n[4]) * 100 + int(n[5]) * 10 + int(n[6])

    if value % 7 != 0:
        return False

    value = int(n[5]) * 100 + int(n[6]) * 10 + int(n[7])

    if value % 11 != 0:
        return False

    value = int(n[6]) * 100 + int(n[7]) * 10 + int(n[8])

    if value % 13 != 0:
        return False
    
    value = int(n[7]) * 100 + int(n[8]) * 10 + int(n[9])

    if value % 17 != 0:
        return False

    return True

def main():
    start = default_timer()

    perm = list(permutations('0123456789'))

    sum_ = 0

    for i in perm:
        if has_property(i):
            sum_ = sum_ + int(''.join(map(str, i)))

    end = default_timer()

    print('Project Euler, Problem 43')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
