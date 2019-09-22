#!/usr/bin/python3

from timeit import default_timer

def main():
    start = default_timer()

    N = 1001

    limit = N * N

    i = 0
    j = 1
    step = 0
    sum_ = 1

    while j < limit:
        if i == 0:
            step = step + 2
        j = j + step
        sum_ = sum_ + j
        i = (i + 1) % 4

    end = default_timer()

    print('Project Euler, Problem 28')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
