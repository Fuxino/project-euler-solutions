#!/usr/bin/python

# Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.
#
# 37 36 35 34 33 32 31
# 38 17 16 15 14 13 30
# 39 18  5  4  3 12 29
# 40 19  6  1  2 11 28
# 41 20  7  8  9 10 27
# 42 21 22 23 24 25 26
# 43 44 45 46 47 48 49
#
# It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers
# lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.
#
# If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued,
# what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?

from timeit import default_timer
from projecteuler import is_prime

def main():
    start = default_timer()

#   Starting with 1, the next four numbers in the diagonal are 3 (1+2), 5 (1+2+2), 7 (1+2+2+2)
#   and 9 (1+2+2+2+2). Check which are prime, increment the counter every time a new prime is 
#   found, and divide by the number of elements of the diagonal, which are increase by 4 at 
#   every cycle. The next four number added to the diagonal are 13 (9+4), 17 (9+4+4), 21 and 25.
#   Then 25+6 etc., at every cycle the step is increased by 2. Continue until the ratio goes below 0.1.
    i = 1
    l = 1
    step = 2
    count = 0
    diag = 5

    while 1:
        i = i + step

        if is_prime(i):
            count = count + 1

        i = i + step

        if is_prime(i):
            count = count + 1

        i = i + step

        if is_prime(i):
            count = count + 1

        i = i + step
        ratio = count / diag

        step = step + 2
        diag = diag + 4
        l = l + 2
        
        if ratio < 0.1:
            break

    end = default_timer()

    print('Project Euler, Problem 58')
    print('Answer: {}'.format(l))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
