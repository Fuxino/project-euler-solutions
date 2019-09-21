#!/usr/bin/python3

from timeit import default_timer
from projecteuler import is_palindrome

def main():
    start = default_timer()

    sum_ = 0

    for i in range(1, 1000000):
        if is_palindrome(i, 10) and is_palindrome(i, 2):
            sum_ = sum_ + i

    end = default_timer()

    print('Project Euler, Problem 36')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
