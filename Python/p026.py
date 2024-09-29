#!/usr/bin/env python3

# A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
#
# 1/2	= 	0.5
# 1/3	= 	0.(3)
# 1/4	= 	0.25
# 1/5	= 	0.2
# 1/6	= 	0.1(6)
# 1/7	= 	0.(142857)
# 1/8	= 	0.125
# 1/9	= 	0.(1)
# 1/10	= 	0.1
#
# Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
#
# Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

from projecteuler import timing


@timing
def p026() -> None:
    _max = 0
    max_n = -1

    for i in range(2, 1000):
        j = i

        # The repeating cycle of 1/(2^a*5^b*p^c*...) is equal to that of 1/p^c*..., so factors 2 and 5 can be eliminated.
        while j % 2 == 0 and j > 1:
            j = j // 2

        while j % 5 == 0 and j > 1:
            j = j // 5

        # If the denominator had only factors 2 and 5, there is no repeating cycle.
        if j == 1:
            n = 0
        else:
            n = 1
            k = 9
            div = j

            # After eliminating factors 2s and 5s, the length of the repeating cycle
            # of 1/d is the smallest n for which k=10^n-1/d is an integer. So we start
            # with k=9, then k=99, k=999 and  so on until k is divisible by d.
            # The number  of digits of k is the length of the repeating cycle.
            while k % div != 0:
                n = n + 1
                k = k * 10
                k = k + 9

            if n > _max:
                _max = n
                max_n = i

    print('Project Euler, Problem 26')
    print(f'Answer: {max_n}')


if __name__ == '__main__':
    p026()
