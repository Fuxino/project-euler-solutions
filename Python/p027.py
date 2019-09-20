#!/usr/bin/python3

from timeit import default_timer
from projecteuler import is_prime

def main():
    start = default_timer()

    max_ = 0

    for a in range(-999, 1000):
        for b in range(2, 1001):
            n = 0
            count = 0

            while True:
                p = n * n + a * n + b

                if p > 1 and is_prime(p):
                    count = count + 1
                    n = n + 1
                else:
                    break

            if count > max_:
                max_ = count
                save_a = a
                save_b = b

    end = default_timer()

    print('Project Euler, Problem 27')
    print('Answer: {}'.format(save_a * save_b))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
