#!/usr/bin/python

# It is well known that if the square root of a natural number is not an integer, then it is irrational.
# The decimal expansion of such square roots is infinite without any repeating pattern at all.
#
# The square root of two is 1.41421356237309504880..., and the digital sum of the first one hundred decimal digits is 475.
#
# For the first one hundred natural numbers, find the total of the digital sums of the first one hundred decimal digits
# for all the irrational square roots

from mpmath import sqrt, mp

from timeit import default_timer

def is_square(n):
    p = sqrt(n)
    m = int(p)

    if p == m:
        return True
    else:
        return False

def main():
    start = default_timer()

#   Set the precision to 100 digits
    mp.dps = 102

    sum_ = 0

    for i in range(2, 100):
        if not is_square(i):
#           Calculate the square root of the current number with the given precision
#           and sum the digits to the total.
            root = str(sqrt(i))

            sum_ = sum_ + int(root[0])

            for j in range(2, 101):
                sum_ = sum_ + int(root[j])

    end = default_timer()

    print('Project Euler, Problem 80')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
