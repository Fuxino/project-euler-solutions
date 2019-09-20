#!/usr/bin/python3

import math

from timeit import default_timer

def is_abundant(n):
    limit = math.floor(math.sqrt(n)) + 1
    sum_ = 1

    for i in range(2, limit):
        if n % i == 0:
            sum_ = sum_ + i
            if n != i * i:
                sum_ = sum_ + n // i

    return sum_ > n

def main():
    start = default_timer()

    ab_nums = [False] * 28124

    for i in range(12, 28124):
        ab_nums[i] = is_abundant(i)

    sums = [False] * 28124

    for i in range(1, 28123):
        if ab_nums[i]:
            for j in range(i, 28123):
                if ab_nums[j]:
                    sum_ = i + j
                    if sum_ <= 28123:
                        sums[sum_] = True

    sum_ = 0

    for i in range(1, 28124):
        if not sums[i]:
            sum_ = sum_ + i

    end = default_timer()

    print('Project Euler, Problem 23')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
