#!/usr/bin/python3

from timeit import default_timer
from projecteuler import gcd

def main():
    start = default_timer()

    prod_n = 1
    prod_d = 1

    for i in range(11, 100):
        for j in range(11, 100):
            if i % 10 != 0 and j % 10 != 0 and\
            i != j and i % 10 == j // 10:
                n = i // 10
                d = j % 10

                f1 = i / j
                f2 = n / d

                if f1 == f2:
                    prod_n = prod_n * i
                    prod_d = prod_d * j

    div = gcd(prod_n, prod_d)

    end = default_timer()

    print('Project Euler, Problem 33')
    print('Answer: {}'.format(prod_d // div))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
