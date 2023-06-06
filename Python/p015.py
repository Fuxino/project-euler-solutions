#!/usr/bin/env python3

# Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner
# How many such routes are there through a 20×20 grid?

from math import factorial
from timeit import default_timer


def main():
    start = default_timer()

#   Using a combinatorial solution: in a 20x20 grid there will always be
#   20 movements to the right and 20 movements down, that can be represented
#   as a string of Rs and Ds. The number of routes is the number of combinations.
#   This is obtained calculating n!/(k!*(n-k)!), where n=40 and k=20.
    count = factorial(40)
    tmp = factorial(20)
    tmp = tmp * tmp
    count = count // tmp

    end = default_timer()

    print('Project Euler, Problem 15')
    print(f'Answer: {count}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
