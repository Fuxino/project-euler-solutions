#!/usr/bin/python

# It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
#
# Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.*

from numpy import zeros

from timeit import default_timer

def have_same_digits(a, b):
    digits1 = zeros(10, int)
    digits2 = zeros(10, int)

#   Get digits of a.
    while a > 0:
        digits1[a%10] = digits1[a%10] + 1
        a = a // 10

#   Get digits of b.
    while b > 0:
        digits2[b%10] = digits2[b%10] + 1
        b = b // 10

#   If they're not the same, return 0.
    for i in range(10):
        if digits1[i] != digits2[i]:
            return 0

    return 1

def main():
    start = default_timer()

    i = 1

#   Brute force approach, try every integer number until the desired one is found.
    while 1:
        if have_same_digits(i, 2*i) and have_same_digits(i, 3*i) and have_same_digits(i, 4*i) and\
                have_same_digits(i, 5*i) and have_same_digits(i, 6*i):
                    break
        i = i + 1
    
    end = default_timer()

    print('Project Euler, Problem 52')
    print('Answer: {}'.format(i))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
