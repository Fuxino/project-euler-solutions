#!/usr/bin/python3

# Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
# If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
#
# For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
# The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
#
# Evaluate the sum of all the amicable numbers under 10000.

from math import floor, sqrt

from timeit import default_timer
from projecteuler import sum_of_divisors

def main():
    start = default_timer()

    sum_ = 0

    for i in range(2, 10000):
#       Calculate the sum of proper divisors with the function
#       implemented in projecteuler.py.
        n = sum_of_divisors(i)
#       If i!=n and the sum of proper divisors of n=i,
#       sum the pair of numbers and add it to the total.
        if i != n and sum_of_divisors(n) == i:
            sum_ = sum_ + i + n

    sum_ = sum_ // 2

    end = default_timer()

    print('Project Euler, Problem 21')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
