#!/usr/bin/python3

from math import factorial

from timeit import default_timer

def main():
    start = default_timer()

    n = str(factorial(100))

    sum_ = 0

    for i in n:
        sum_ = sum_ + int(i)

    end = default_timer()

    print('Project Euler, Problem 20')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
