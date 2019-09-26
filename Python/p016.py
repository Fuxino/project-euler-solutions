#!/usr/bin/python3

# 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
#
# What is the sum of the digits of the number 2^1000?

from timeit import default_timer

def main():
    start = default_timer()

#   Simply calculate 2^1000, convert the result to string and calculate
#   the sum of the digits
    res = str(2 ** 1000)

    sum_ = 0

    for i in res:
        sum_ = sum_ + int(i)

    end = default_timer()

    print('Project Euler, Problem 16')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
