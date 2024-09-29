#!/usr/bin/env python3

# Take the number 192 and multiply it by each of 1, 2, and 3:
#
# 192 × 1 = 192
# 192 × 2 = 384
# 192 × 3 = 576
#
# By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
#
# The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated
# product of 9 and (1,2,3,4,5).
#
# What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

from projecteuler import is_pandigital, timing


@timing
def p038() -> None:
    _max = 0

    # A brute force approach is used, starting with 1 and multiplying
    # the number by 1, 2 etc., concatenating the results, checking if
    # it's 1 to 9 pandigital, and going to the next number when the
    # concatenated result is greater than the greatest 9 digit pandigital
    # value. The limit is set to 10000, since 1*10000=10000, 2*10000=20000 and
    # concatenating this two numbers a 10-digit number is obtained.
    for i in range(1, 10000):
        n = 0
        j = 1

        while True:
            tmp = i * j
            n = n + tmp
            j = j + 1

            if n > _max and is_pandigital(n, 9):
                _max = n
            if i * j < 10:
                n = n * 10
            elif i * j < 100:
                n = n * 100
            elif i * j < 1000:
                n = n * 1000
            elif i * j < 10000:
                n = n * 10000
            elif i * j < 100000:
                n = n * 100000

            if n > 987654321:
                break

    print('Project Euler, Problem 38')
    print(f'Answer: {_max}')


if __name__ == '__main__':
    p038()
