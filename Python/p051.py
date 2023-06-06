#!/usr/bin/python

# By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
#
# By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten
# generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this
# family, is the smallest prime with this property.
#
# Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime
# value family.

from timeit import default_timer

from projecteuler import sieve


N = 1000000

# N set to 1000000 as a reasonable limit, which turns out to be enough.
primes = sieve(N)


def count_digit(n, d):
    count = 0

    while n > 0:
        if n % 10 == d:
            count = count + 1
        n = n // 10

    return count


def replace(n):
    n_string = list(str(n))
    l = len(n_string)
    max_ = 0

    for i in range(l-3):
        for j in range(i+1, l-2):
#             Replacing the last digit can't give 8 primes, because at least
#             six of the numbers obtained will be divisible by 2 and/or 5.
            for k in range(j+1, l-1):
                count = 0

                for w in range(10):
                    if i == 0 and w == 0:
                        continue

                    n_string = list(str(n))
                    n_string[i] = str(w)
                    n_string[j] = str(w)
                    n_string[k] = str(w)

                    n_replaced = int(''.join(n_string))

                    if primes[n_replaced] == 1:
                        if count == 0 and n_replaced != n:
                            continue
                        count = count + 1

                if count > max_:
                    max_ = count

    return max_

def main():
    start = default_timer()

#   Checking only odd numbers with at least 4 digits.
    i = 1001

    while i < N:
#       The family of numbers needs to have at least one of 0, 1 or 2 as
#       repeated digits, otherwise we can't get a 8 number family (there
#       are only 7 other digits). Also, te number of repeated digits must
#       be 3, otherwise at least 3 resulting numbers will be divisible by 3.
#       So the smallest number of this family must have three 0s, three 1s or
#       three 2s.
        if count_digit(i, 0) >= 3 or count_digit(i, 1) >= 3 or\
                count_digit(i, 2) >= 3:
            if primes[i] == 1 and replace(i) == 8:
                break
        i = i + 2

    end = default_timer()

    print('Project Euler, Problem 51')
    print(f'Answer: {i}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
