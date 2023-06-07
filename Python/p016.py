#!/usr/bin/env python3

# 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
#
# What is the sum of the digits of the number 2^1000?

from projecteuler import timing


@timing
def p016():
    # Simply calculate 2^1000, convert the result to string and calculate
    # the sum of the digits
    res = str(2 ** 1000)

    sum_ = 0

    for i in res:
        sum_ = sum_ + int(i)

    print('Project Euler, Problem 16')
    print(f'Answer: {sum_}')


if __name__ == '__main__':
    p016()
