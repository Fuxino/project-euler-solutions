#!/usr/bin/python3

from timeit import default_timer
from projecteuler import is_prime

def is_tr_prime(n):
    if n < 11 or not is_prime(n):
        return False

    tmp = n // 10

    while tmp > 0:
        if not is_prime(tmp):
            return False
        tmp = tmp // 10

    i = 10
    tmp = n % i

    while tmp != n:
        if not is_prime(tmp):
            return False
        i = i * 10
        tmp = n % i

    return True

def main():
    start = default_timer()

    i = 0
    n = 1
    sum_ = 0

    while i < 11:
        if is_tr_prime(n):
            sum_ = sum_ + n
            i = i + 1
        n = n + 1

    end = default_timer()

    print('Project Euler, Problem 37')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
