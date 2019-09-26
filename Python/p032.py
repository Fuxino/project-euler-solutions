#!/usr/bin/python3

# We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234,
# is 1 through 5 pandigital.
#
# The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
#
# Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
#
# HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

import numpy as np
from numpy import zeros

from timeit import default_timer
from projecteuler import is_pandigital

def main():
    start = default_timer()

    n = 0
#   Initially I used a bigger array, but printing the resulting products
#   shows that 10 values are sufficient.
    products = zeros(10, int)

#   To get a 1 to 9 pandigital concatenation of the two factors and product,
#   we need to multiply a 1 digit number times a 4 digit numbers (the biggest
#   one digit number 9 times the biggest 3 digit number 999 multiplied give
#   8991 and the total digit count is 8, which is not enough), or a 2 digit 
#   number times a 3 digit number (the smallest two different 3 digits number,
#   100 and 101, multiplied give 10100, and the total digit count is 11, which
#   is too many). The outer loop starts at 2 because 1 times any number gives
#   the same number, so its digit will be repeated and the result can't be 
#   pandigital. The nested loop starts from 1234 because it's the smallest 
#   4-digit number with no repeated digits, and it ends at 4987 because it's
#   the biggest number without repeated digits that multiplied by 2 gives a 
#   4 digit number.
    for i in range(2, 9):
        for j in range(1234, 4987):
            p = i * j
            num_s = str(i) + str(j) + str(p)

            if len(num_s) > 9:
                break

            num = int(num_s)

            if is_pandigital(num, 9):
                products[n] = p
                n = n + 1

#   The outer loop starts at 12 because 10 has a 0 and 11 has two 1s, so
#   the result can't be pandigital. The nested loop starts at 123 because
#   it's the smallest 3-digit number with no digit repetitions and ends at
#   833, because 834*12 has 5 digits.
    for i in range(12, 99):
        for j in range(123, 834):
            p = i * j

            num_s = str(i) + str(j) + str(p)

            if len(num_s) > 9:
                break

            num = int(num_s)

            if is_pandigital(num, 9):
                products[n] = p
                n = n + 1

#   Sort the found products to easily see if there are duplicates.
    products = np.sort(products[:n])

    sum_ = products[0]

    for i in range(1, n):
        if products[i] != products[i-1]:
            sum_ = sum_ + products[i]

    end = default_timer()

    print('Project Euler, Problem 32')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
