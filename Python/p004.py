#!/usr/bin/python3

from timeit import default_timer
from projecteuler import is_palindrome

def main():
    start = default_timer()

    max_ = 0

    for i in range(999, 99, -1):
        for j in range(i, 99, -1):
            num = i * j
            if num > max_ and is_palindrome(num, 10):
                max_ = num

    end = default_timer()

    print('Project Euler, Problem 4')
    print('Answer: {}'.format(max_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
