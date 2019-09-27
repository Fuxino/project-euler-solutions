#!/usr/bin/python

# It is possible to show that the square root of two can be expressed as an infinite continued fraction.
#
# √2=1+1/(2+1/(2+1/(2+…
#
# By expanding this for the first four iterations, we get:
#
# 1+1/2=3/2=1.5
# 1+1/(2+1/2)=7/5=1.4
# 1+1/(2+1/(2+1/2))=17/12=1.41666…
# 1+1/(2+1/(2+1/(2+1/2)))=41/29=1.41379…
#
# The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, is the first example where the number of digits
# in the numerator exceeds the number of digits in the denominator.
#
# In the first one-thousand expansions, how many fractions contain a numerator with more digits than the denominator?

from timeit import default_timer

def count_digits(n):
    count = 0

    while n > 0:
        n = n // 10
        count = count + 1

    return count

def main():
    start = default_timer()

    n = 1
    d = 1
    count = 0

#   If n/d is the current term of the expansion, the next term can be calculated as
#   (n+2d)/(n+d).
    for i in range(1, 1000):
        d2 = 2 * d
        d = n + d
        n = n +  d2

        if count_digits(n) > count_digits(d):
            count = count + 1

    end = default_timer()

    print('Project Euler, Problem 57')
    print('Answer: {}'.format(count))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
