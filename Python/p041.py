#!/usr/bin/python3

# We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital
# and is also prime.
#
# What is the largest n-digit pandigital prime that exists?

from timeit import default_timer
from projecteuler import is_pandigital, is_prime

def count_digits(n):
    i = 0

    while n > 0:
        i = i + 1
        n = n // 10

    return i

def main():
    start = default_timer()

#   8- and 9-digit pandigital numbers can't be prime, because
#   1+2+...+8=36, which is divisible by 3, and 36+9=45 which is
#   also divisible by 3, and therefore the whole number is divisible
#   by 3. So we can start from the largest 7-digit pandigital number,
#   until we find a prime.
    i = 7654321

    while(i > 0):
        if is_pandigital(i, count_digits(i)) and is_prime(i):
            break
#       Skipping the even numbers.
        i = i - 2
    
    end = default_timer()

    print('Project Euler, Problem 41')
    print('Answer: {}'.format(i))
    
    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
