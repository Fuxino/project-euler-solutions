#!/usr/bin/python3

import math

from timeit import default_timer

def sum_of_divisors(n):
    limit = math.floor(math.sqrt(n)) + 1

    sum_ = 1

    for i in range(2, limit):
        if n % i == 0:
            sum_ = sum_ + i
            if n != i * i:
                sum_ = sum_ + n // i

    return sum_

def main():
    start = default_timer()

    sum_ = 0

    for i in range(2, 10000):
        n = sum_of_divisors(i)
        if i != n and sum_of_divisors(n) == i:
            sum_ = sum_ + i + n

    sum_ = sum_ // 2

    end = default_timer()

    print('Project Euler, Problem 21')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
