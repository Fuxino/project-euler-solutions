#!/usr/bin/python

# It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
#
# Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

from timeit import default_timer


def main():
    start = default_timer()

    i = 1

#   Brute force approach, try every integer number until the desired one is found.
    while True:
        if ''.join(sorted(str(i))) == ''.join(sorted(str(2*i))) and\
                ''.join(sorted(str(i))) == ''.join(sorted(str(3*i))) and\
                ''.join(sorted(str(i))) == ''.join(sorted(str(4*i))) and\
                ''.join(sorted(str(i))) == ''.join(sorted(str(5*i))) and\
                ''.join(sorted(str(i))) == ''.join(sorted(str(6*i))):
            break
        i = i + 1

    end = default_timer()

    print('Project Euler, Problem 52')
    print(f'Answer: {i}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
