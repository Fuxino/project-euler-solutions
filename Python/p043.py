#!/usr/bin/env python3

# The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a
# rather interesting sub-string divisibility property.
#
# Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
#
# d2d3d4=406 is divisible by 2
# d3d4d5=063 is divisible by 3
# d4d5d6=635 is divisible by 5
# d5d6d7=357 is divisible by 7
# d6d7d8=572 is divisible by 11
# d7d8d9=728 is divisible by 13
# d8d9d10=289 is divisible by 17
#
# Find the sum of all 0 to 9 pandigital numbers with this property.

from itertools import permutations

from projecteuler import timing


# Function to check if the value has the desired property.
def has_property(n):
    value = int(n[1]) * 100 + int(n[2]) * 10 + int(n[3])

    if value % 2 != 0:
        return False

    value = int(n[2]) * 100 + int(n[3]) * 10 + int(n[4])

    if value % 3 != 0:
        return False

    value = int(n[3]) * 100 + int(n[4]) * 10 + int(n[5])

    if value % 5 != 0:
        return False

    value = int(n[4]) * 100 + int(n[5]) * 10 + int(n[6])

    if value % 7 != 0:
        return False

    value = int(n[5]) * 100 + int(n[6]) * 10 + int(n[7])

    if value % 11 != 0:
        return False

    value = int(n[6]) * 100 + int(n[7]) * 10 + int(n[8])

    if value % 13 != 0:
        return False

    value = int(n[7]) * 100 + int(n[8]) * 10 + int(n[9])

    if value % 17 != 0:
        return False

    return True


@timing
def p043():
    # Find all the permutations
    perm = list(permutations('0123456789'))

    sum_ = 0

    # For each permutation, check if it has the required property
    for i in perm:
        if has_property(i):
            sum_ = sum_ + int(''.join(map(str, i)))

    print('Project Euler, Problem 43')
    print(f'Answer: {sum_}')


if __name__ == '__main__':
    p043()
