#!/usr/bin/env python3

# Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0,
# where each “_” is a single digit.

from timeit import default_timer


def main():
    start = default_timer()

#   Since the square of n has 19 digits, n must be at least 10^9.
    n = 1000000000
    found = 0

    while not found:
#       If the square on n ends with 10, n must be divisible by 10.
        n = n + 10
        p = n * n

#       A square divisible by 10 is also divisible by 100.
        if p % 100 != 0:
            continue

#       Check if the digits of the square correspond to the given pattern.
        i = 9
        p = p // 100

        while p > 0:
            if p % 10 != i:
                break
            p = p // 100
            i = i - 1

        if p == 0:
            found = 1

    end = default_timer()

    print('Project Euler, Problem 206')
    print(f'Answer: {n}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
