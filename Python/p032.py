#!/usr/bin/python3

import numpy as np
from numpy import zeros

from timeit import default_timer

def main():
    start = default_timer()

    n = 0
    products = zeros(100, int)

    for i in range(2, 100):
        for j in range(100, 10000):
            a = i
            b = j
            p = a * b

            digits = zeros(10, int)

            while True:
                d = a % 10
                digits[d] = digits[d] + 1
                a = a // 10

                if a <= 0:
                    break

            while True:
                d = b % 10
                digits[d] = digits[d] + 1
                b = b // 10

                if b <= 0:
                    break

            p1 = p

            while True:
                d = p1 % 10
                digits[d] = digits[d] + 1
                p1 = p1 // 10

                if p1 <= 0:
                    break

            k = 0

            if digits[0] == 0:
                for k in range(1, 11):
                    if k > 9 or digits[k] > 1 or digits[k] == 0:
                        break

            if k == 10:
                products[n] = p
                n = n + 1

    products = np.sort(products)

    sum_ = products[0]

    for i in range(1, 100):
        if products[i] != products[i-1]:
            sum_ = sum_ + products[i]

    end = default_timer()

    print('Project Euler, Problem 32')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
