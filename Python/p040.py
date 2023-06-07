#!/usr/bin/env python3

# An irrational decimal fraction is created by concatenating the positive integers:
#
# 0.123456789101112131415161718192021...
#
# It can be seen that the 12th digit of the fractional part is 1.
#
# If d_n represents the nth digit of the fractional part, find the value of the following expression.
#
# d_1 × d_10 × d_100 × d_1000 × d_10000 × d_100000 × d_1000000

from numpy import zeros

from projecteuler import timing


@timing
def p040():
    digits = zeros(1000005, int)
    i = 1
    value = 1

    # Loop on all numbers and put the digits in the right place
    # in an array. Use modulo and division to get the digits
    # for numbers with more than one digit.
    while i <= 1000000:
        if value < 10:
            digits[i-1] = value
            i = i + 1
        elif value < 100:
            digits[i-1] = value / 10
            digits[i] = value % 10
            i = i + 2
        elif value < 1000:
            digits[i-1] = value / 100
            digits[i] = (value / 10) % 10
            digits[i+1] = value % 10
            i = i + 3
        elif value < 10000:
            digits[i-1] = value / 1000
            digits[i] = (value / 100) % 10
            digits[i+1] = (value / 10) % 10
            digits[i+2] = value % 10
            i = i + 4
        elif value < 100000:
            digits[i-1] = value / 10000
            digits[i] = (value / 1000) % 10
            digits[i+1] = (value / 100) % 10
            digits[i+2] = (value / 10) % 10
            digits[i+3] = value % 10
            i = i + 5
        elif value < 1000000:
            digits[i-1] = value / 100000
            digits[i] = (value / 10000) % 10
            digits[i+1] = (value / 1000) % 10
            digits[i+2] = (value / 100) % 10
            digits[i+3] = (value / 10) % 10
            digits[i+4] = value % 10
            i = i + 6
        value = value + 1

    # Calculate the product.
    n = digits[0] * digits[9] * digits[99] * digits[999] * digits[9999] * digits[99999] * digits[999999]

    print('Project Euler, Problem 40')
    print(f'Answer: {n}')


if __name__ == '__main__':
    p040()
