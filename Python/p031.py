#!/usr/bin/python3

# In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
#
# 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
#
# It is possible to make £2 in the following way:
#
# 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
#
# How many different ways can £2 be made using any number of coins?

from timeit import default_timer

# Simple recursive function that tries every combination.
def count(coins, value, n, i):
    for j in range(i, 8):
        value = value + coins[j]
        if value == 200:
            return n + 1
        elif value > 200:
            return n
        else:
            n = count(coins, value, n, j)
            value = value - coins[j]

    return n

def main():
    start = default_timer()

    coins = [1, 2, 5, 10, 20, 50, 100, 200]

    n = count(coins, 0, 0, 0)

    end = default_timer()

    print('Project Euler, Problem 31')
    print('Answer: {}'.format(n))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
