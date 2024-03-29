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

from projecteuler import timing


@timing
def p057():
    n = 1
    d = 1
    count = 0

    # If n/d is the current term of the expansion, the next term can be calculated as
    # (n+2d)/(n+d).
    for _ in range(1, 1000):
        d2 = 2 * d
        d = n + d
        n = n + d2

        if len(str(n)) > len(str(d)):
            count = count + 1

    print('Project Euler, Problem 57')
    print(f'Answer: {count}')


if __name__ == '__main__':
    p057()
