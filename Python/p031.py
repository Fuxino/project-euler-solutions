#!/usr/bin/python3

from timeit import default_timer

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

    print('Project Euler, Problem 30')
    print('Answer: {}'.format(n))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
