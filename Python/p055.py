#!/usr/bin/python

# If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.
#
# Not all numbers produce palindromes so quickly. For example,
#
# 349 + 943 = 1292,
# 1292 + 2921 = 4213
# 4213 + 3124 = 7337
#
# That is, 349 took three iterations to arrive at a palindrome.
#
# Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome
# through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, 
# we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either 
# (i) become a palindrome in less than fifty iterations, or,
# (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown
# to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).
#
# Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.
#
# How many Lychrel numbers are there below ten-thousand?
#
# NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.

from timeit import default_timer
from projecteuler import is_palindrome

def is_lychrel(n):
    tmp = n

#   Run for 50 iterations
    for i in range(50):
        reverse = 0

#       Find the reverse of the given number
        while tmp > 0:
            reverse = reverse * 10
            reverse = reverse + tmp % 10
            tmp = tmp // 10

#       Add the reverse to the original number
        tmp = n + reverse

#       If the sum is palindrome, the number is not a Lychrel number.
        if is_palindrome(tmp, 10):
            return 0

        n = tmp

    return 1

def main():
    start = default_timer()

    count = 0

#   For each number, use the is_lychrel function to check if the number
#   is a Lychrel number.
    for i in range(1, 10000):
        if is_lychrel(i):
            count = count + 1

    end = default_timer()

    print('Project Euler, Problem 55')
    print('Answer: {}'.format(count))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
