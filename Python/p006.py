#!/usr/bin/python3

# The sum of the squares of the first ten natural numbers is,
#
# 1^2 + 2^2 + ... + 10^2 = 385
#
# The square of the sum of the first ten natural numbers is,
#
# (1 + 2 + ... + 10)^2 = 55^2 = 3025
#
# Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
#
# Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

from timeit import default_timer

def main():
    start = default_timer()

    sum_squares = 0
    square_sum = 0

#   Straightforward brute-force approach.
    for i in range(1, 101):
        sum_squares = sum_squares + i * i
        square_sum = square_sum + i

    square_sum = square_sum * square_sum

    end = default_timer()

    print('Project Euler, Problem 6')
    print('Answer: {}'.format(square_sum - sum_squares))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
