#!/usr/bin/python3

from timeit import default_timer

def is_palindrome(num, base):
    reverse = 0

    tmp = num

    while tmp > 0:
        reverse = reverse * base
        reverse = reverse + tmp % base
        tmp = tmp // base

    if num == reverse:
        return 1

    return 0

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
