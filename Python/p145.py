#!/usr/bin/python

# Some positive integers n have the property that the sum [ n + reverse(n) ] consists entirely of odd (decimal) digits.
# For instance, 36 + 63 = 99 and 409 + 904 = 1313. We will call such numbers reversible; so 36, 63, 409, and 904 are reversible.
# Leading zeroes are not allowed in either n or reverse(n).
#
# There are 120 reversible numbers below one-thousand.
#
# How many reversible numbers are there below one-billion (109)?

from projecteuler import timing


@timing
def p145():
    N = 1000000000

    count = 0

    # Brute force approach, sum each number and their reverse and
    # check if there are only odd digits.
    for i in range(11, N):
        if i % 10 != 0:
            s = str(i + int(''.join(reversed(str(i)))))

            if '0' not in s and '2' not in s and '4' not in s and\
                    '6' not in s and '8' not in s:
                count = count + 1

    print('Project Euler, Problem 145')
    print(f'Answer: {count}')


if __name__ == '__main__':
    p145()
