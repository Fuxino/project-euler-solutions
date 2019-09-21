#!/usr/bin/python3

from numpy import zeros

from timeit import default_timer

def main():
    start = default_timer()

    digits = zeros(1000005, int)
    i = 1
    value = 1

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

    n = digits[0] * digits[9] * digits[99] * digits[999] * digits[9999] * digits[99999] * digits[999999]

    end = default_timer()

    print('Project Euler, Problem 40')
    print('Answer: {}'.format(n))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
