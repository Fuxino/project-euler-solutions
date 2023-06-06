#!/usr/bin/env python3

# A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
# For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
#
# A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
#
# As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
# By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
# However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed
# as the sum of two abundant numbers is less than this limit.
#
# Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

from timeit import default_timer

from projecteuler import sum_of_divisors


def is_abundant(n):
    return sum_of_divisors(n) > n


def main():
    start = default_timer()

    ab_nums = [False] * 28124

#   Find all abundant numbers smaller than 28123.
    for i in range(12, 28124):
        ab_nums[i] = is_abundant(i)

    sums = [False] * 28124

#   For every abundant number, sum every other abundant number greater
#   than itself, until the sum exceeds 28123. Record that the resulting
#   number is the sum of two abundant numbers.
    for i in range(1, 28123):
        if ab_nums[i]:
            for j in range(i, 28123):
                if ab_nums[j]:
                    sum_ = i + j
                    if sum_ <= 28123:
                        sums[sum_] = True

    sum_ = 0

#   Sum every number that was not found as a sum of two abundant numbers.
    for i in range(1, 28124):
        if not sums[i]:
            sum_ = sum_ + i

    end = default_timer()

    print('Project Euler, Problem 23')
    print(f'Answer: {sum_}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
