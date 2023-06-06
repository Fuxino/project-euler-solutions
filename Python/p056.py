#!/usr/bin/python

# A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^100 is almost unimaginably large: one followed by two-hundred zeros.
# Despite their size, the sum of the digits in each number is only 1.
#
# Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?

from timeit import default_timer


def main():
    start = default_timer()

    max_ = 0

#   Straightforward brute force approach
    for a in range(1, 100):
        for b in range(1, 100):
            p = a ** b
            sum_ = 0

            while p > 0:
                sum_ = sum_ + p % 10
                p = p // 10

            if sum_ > max_:
                max_ = sum_

    end = default_timer()

    print('Project Euler, Problem 56')
    print(f'Answer: {max_}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
