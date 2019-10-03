#!/usr/bin/python

# Some positive integers n have the property that the sum [ n + reverse(n) ] consists entirely of odd (decimal) digits.
# For instance, 36 + 63 = 99 and 409 + 904 = 1313. We will call such numbers reversible; so 36, 63, 409, and 904 are reversible.
# Leading zeroes are not allowed in either n or reverse(n).
#
# There are 120 reversible numbers below one-thousand.
#
# How many reversible numbers are there below one-billion (109)?

from timeit import default_timer

def main():
    start = default_timer()

    N = 10000000
    
    count = 0

#   Brute force approach, sum each number and their reverse and
#   check if there are only odd digits.
    for i in range(11, N):
        if i % 10 != 0:
            s = str(i + int(''.join(reversed(str(i)))))

            if not '0' in s and not '2' in s and not '4' in s and\
                    not '6' in s and not '8' in s:
                count = count + 1

    end = default_timer()

    print('Project Euler, Problem 145')
    print('Answer: {}'.format(count))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
