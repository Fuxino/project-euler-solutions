#!/usr/bin/python3

from math import factorial

from numpy import ones

from timeit import default_timer

def main():
    start = default_timer()

    a = 10
    sum_ = 0
    factorials = ones(10, int)

    for i in range(2, 10):
        factorials[i] = factorial(i)

    while a < 50000:
        b = a
        sum_f = 0

        while b != 0:
            digit = b % 10
            b = b // 10
            sum_f = sum_f + factorials[digit]

        if a == sum_f:
            sum_ = sum_ + a

        a = a + 1

    end = default_timer()

    print('Project Euler, Problem 34')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
