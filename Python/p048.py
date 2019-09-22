#!/usr/bin/python3

from timeit import default_timer

def main():
    start = default_timer()

    sum_ = 0

    for i in range(1, 1001):
        power = i ** i
        sum_ = sum_ + power

    end = default_timer()

    print('Project Euler, Problem 48')
    print('Answer: {}'.format(str(sum_)[-10:]))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
