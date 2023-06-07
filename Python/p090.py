#!/usr/bin/env python3

# Each of the six faces on a cube has a different digit (0 to 9) written on it; the same is done to a second cube. By placing the two cubes side-by-side in different positions we can form a variety of 2-digit numbers.
#
# For example, the square number 64 could be formed:
#                       |6||4|
#
# In fact, by carefully choosing the digits on both cubes it is possible to display all of the square numbers below one-hundred: 01, 04, 09, 16, 25, 36, 49, 64, and 81.
#
# For example, one way this can be achieved is by placing {0,5,6,7,8,9} on one cube and {1,2,3,4,8,9} on the other cube.
#
# However, for this problem we shall allow the 6 or 9 to be turned upside-down so that an arrangement like  {0,5,6,7,8,9} and  {1,2,3,4,6,7} allows for all nine square numbers to be displayed; otherwise it would be impossible to obtain 09.
#
# In determining a distinct arrangement we are interested in the digits on each cube, not the order.
#
#   {1,2,3,4,5,6} is equivalent to {3,6,4,1,2,5}
#   {1,2,3,4,5,6} is distinct from {1,2,3,4,5,9}
#
# But because we are allowing 6 and 9 to be reversed, the two distinct sets in the last example both represent the extended set {1,2,3,4,5,6,9} for the purpose of forming 2-digit numbers.
#
# How many distinct arrangements of the two cubes allow for all of the square numbers to be displayed?

from copy import copy
from itertools import product

from projecteuler import timing


N = 10
K = 6
COMBINATIONS = []


def combination(i, k, comb):
    if len(comb) == K:
        COMBINATIONS.append(copy(comb))

        return

    for j in range(i, N - k + 1):
        comb.append(j)
        combination(j + 1, k - 1, comb)
        comb.pop()


@timing
def p090():
    squares = [1, 4, 9, 16, 25, 36, 49, 64, 81]
    combination(0, K, [])

    for c in COMBINATIONS:
        if 6 in c and 9 not in c:
            c.append(9)
        if 9 in c and 6 not in c:
            c.append(6)

    count = 0

    for i, c in enumerate(COMBINATIONS):
        for j in range(i + 1, len(COMBINATIONS)):
            cur_squares = copy(squares)

            prods = list(product(c, COMBINATIONS[j]))
            prods.extend(list(product(COMBINATIONS[j], c)))

            for elem in prods:
                val = int(str(elem[0]) + str(elem[1]))

                if val in cur_squares:
                    cur_squares.remove(val)

                    if len(cur_squares) == 0:
                        count += 1

                        break

    print('Project Euler, Problem 90')
    print(f'Answer: {count}')


if __name__ == '__main__':
    p090()
