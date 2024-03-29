#!/usr/bin/env python3

# The number 145 is well known for the property that the sum of the factorial of its digits is equal to 145:
#
# 1! + 4! + 5! = 1 + 24 + 120 = 145
#
# Perhaps less well known is 169, in that it produces the longest chain of numbers that link back to 169; it turns out that there are
# only three such loops that exist:
#
# 169 → 363601 → 1454 → 169
# 871 → 45361 → 871
# 872 → 45362 → 872
#
# It is not difficult to prove that EVERY starting number will eventually get stuck in a loop. For example,
#
# 69 → 363600 → 1454 → 169 → 363601 (→ 1454)
# 78 → 45360 → 871 → 45361 (→ 871)
# 540 → 145 (→ 145)
#
# Starting with 69 produces a chain of five non-repeating terms, but the longest non-repeating chain with a starting number
# below one million is sixty terms.
#
# How many chains, with a starting number below one million, contain exactly sixty non-repeating terms?

from math import factorial

from projecteuler import timing


N = 1000000
chains = [0] * N


def len_chain(n):
    chain = [0] * 60
    count = 0
    finished = 0

    value = n
    chain[count] = value

    while not finished:
        tmp = 0
        count = count + 1

        # Generate the next number of the chain by taking
        # the digits of the current value, calculating the
        # factorials and adding them.
        while value != 0:
            tmp = tmp + factorial(value % 10)
            value = value // 10

        # If the chain length for the new value has already been
        # calculated before, use the saved value (only chains for
        # values smaller than N are saved).
        if tmp < N and chains[tmp] != 0:
            return count + chains[tmp]

        value = tmp

        # If the current value is already present in the chain,
        # the chain is finished.
        for i in range(count):
            if chain[i] == value:
                finished = 1

        chain[count] = value

    chains[n] = count

    return count


@timing
def p074():
    count = 0

    # Simple brute force approach, for every number calculate
    # the length of the chain.
    for i in range(3, N):
        if len_chain(i) == 60:
            count = count + 1

    print('Project Euler, Problem 74')
    print(f'Answer: {count}')


if __name__ == '__main__':
    p074()
