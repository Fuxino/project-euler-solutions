# Comparing two numbers written in index form like 2^11 and 3^7 is not difficult, as any calculator would confirm that 
# 2^11 = 2048 < 3^7 = 2187.
#
# However, confirming that 632382^518061 > 519432^525806 would be much more difficult, as both numbers contain over three million digits.
#
# Using base_exp.txt, a 22K text file containing one thousand lines with a base/exponent pair on each line, 
# determine which line number has the greatest numerical value.
#
# NOTE: The first two lines in the file represent the numbers in the example given above.*/

import sys
from math import log

from projecteuler import timing


@timing
def p099():
    max_ = 0
    max_i = -1

    try:
        with open('p099_base_exp.txt', 'r', encoding='utf-8') as fp:
            base_exps = fp.readlines()
    except FileNotFoundError:
        print('Error while opening file p099_base_exp.txt')

        sys.exit(1)

    for i in range(1, 1001):
        base_exp = base_exps[i - 1].split(',')
        base = int(base_exp[0])
        exp = int(base_exp[1])

        curr = exp * log(base)

        if curr > max_:
            max_ = curr
            max_i = i

    print('Project Euler, Problem 99')
    print(f'Answer: {max_i}')


if __name__ == '__main__':
    p099()
