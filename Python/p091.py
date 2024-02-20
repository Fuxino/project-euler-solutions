#!/usr/bin/env python3

# The points P(x1,y1) and Q(x2,y2) are plotted at integer co-ordinates and are joined to the origin, O(0,0), to form ΔOPQ.
#
# There are exactly fourteen triangles containing a right angle that can be formed when each co-ordinate lies between 0 and 2 inclusive;
# that is, 0<=x1,y1,x2,y2<=2.
#
# Given that 0<=x1,y1,x2,y2<=50, how many right triangles can be formed?

from itertools import product

from projecteuler import timing


N = 50


def check_triangle(p1, p2, p3):
    a = int((p2[0] - p1[0]) ** 2 + (p2[1] - p1[1]) ** 2)
    b = int((p3[0] - p2[0]) ** 2 + (p3[1] - p2[1]) ** 2)
    c = int((p3[0] - p1[0]) ** 2 + (p3[1] - p1[1]) ** 2)

    if ((a > 0 and b > 0 and c > 0) and
        (a == (b + c) or b == (a + c) or
         c == (a + b))):
        return True

    return False


@timing
def p091():
    combinations = []

    for i in range(N + 1):
        for j in range(N + 1):
            combinations.append((i, j))

    prods = product(combinations, repeat=2)

    count = 0

    for p in prods:
        if check_triangle((0, 0), p[0], p[1]):
            count += 1

    print('Project Euler, Problem 91')
    print(f'Answer: {int(count / 2)}')


if __name__ == '__main__':
    p091()
