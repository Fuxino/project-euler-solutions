#!/usr/bin/python3

# n! means n × (n − 1) × ... × 3 × 2 × 1
#
# For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
# and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
#
# Find the sum of the digits in the number 100!

from math import factorial

from timeit import default_timer

def main():
    start = default_timer()

#   Calculate the factorial, convert the result to string and sum the digits.
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
