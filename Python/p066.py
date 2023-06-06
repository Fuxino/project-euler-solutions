#!/usr/bin/python

# Consider quadratic Diophantine equations of the form:
#
# x^2 – Dy^2 = 1
#
# For example, when D=13, the minimal solution in x is 649^2 – 13×180^2 = 1.
#
# It can be assumed that there are no solutions in positive integers when D is square.
#
# By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:
#
# 3^2 – 2×2^2 = 1
# 2^2 – 3×1^2 = 1
# 9^2 – 5×4^2 = 1
# 5^2 – 6×2^2 = 1
# 8^2 – 7×3^2 = 1
#
# Hence, by considering minimal solutions in x for D ≤ 7, the largest x is obtained when D=5.
#
# Find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.

from math import sqrt
from timeit import default_timer

from projecteuler import pell_eq


def is_square(n):
    p = sqrt(n)
    m = int(p)

    return bool(p == m)


def main():
    start = default_timer()

    max_ = 0
    max_d = -1

    for i in range(2, 1001):
        if not is_square(i):
#           Solve the Diophantine equation x^2-D*y^2=1 (Pell equation)
            x = pell_eq(i)

            if x > max_:
                max_ = x
                max_d = i

    end = default_timer()

    print('Project Euler, Problem 66')
    print(f'Answer: {max_d}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
