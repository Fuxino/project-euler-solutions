#!/usr/bin/env python3

# In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
#
# 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
#
# It is possible to make £2 in the following way:
#
# 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
#
# How many different ways can £2 be made using any number of coins?

from typing import List

from projecteuler import timing


# Simple recursive function that tries every combination.
def count(coins: List[int], value: int, n: int, i: int) -> int:
    for j in range(i, 8):
        value = value + coins[j]

        if value == 200:
            return n + 1

        if value > 200:
            return n

        n = count(coins, value, n, j)
        value = value - coins[j]

    return n


@timing
def p031() -> None:
    coins = [1, 2, 5, 10, 20, 50, 100, 200]

    n = count(coins, 0, 0, 0)

    print('Project Euler, Problem 31')
    print(f'Answer: {n}')


if __name__ == '__main__':
    p031()
