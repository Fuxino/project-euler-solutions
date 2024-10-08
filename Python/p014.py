#!/usr/bin/env python3

# The following iterative sequence is defined for the set of positive integers:
#
# n → n/2 (n is even)
# n → 3n + 1 (n is odd)
#
# Using the rule above and starting with 13, we generate the following sequence:
#
# 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
#
# It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem),
# it is thought that all starting numbers finish at 1.
#
# Which starting number, under one million, produces the longest chain?
#
# NOTE: Once the chain starts the terms are allowed to go above one million.

from numpy import zeros

from projecteuler import timing


N = 1000000
collatz_found = zeros(N, dtype=int)


# Recursive function to calculate the Collatz sequence for n.
# If n is even, Collatz(n)=1+Collatz(n/2), if n is odd
# Collatz(n)=1+Collatz(3*n+1).
def collatz_length(n: int) -> int:

    if n == 1:
        return 1

    # If Collatz(n) has been previously calculated,
    # just return the value.
    if n < N and collatz_found[n]:
        return collatz_found[n]

    if n % 2 == 0:
        return 1 + collatz_length(n//2)

    return 1 + collatz_length(3*n+1)


@timing
def p014() -> None:
    max_l = 0
    _max = 0

    # For each number from 1 to 1000000, find the length of the sequence
    # and save its value, so that it can be used for the next numbers.
    for i in range(1, N):
        count = collatz_length(i)
        collatz_found[i] = count

        if count > max_l:
            max_l = count
            _max = i

    print('Project Euler, Problem 14')
    print(f'Answer: {_max}')


if __name__ == '__main__':
    p014()
