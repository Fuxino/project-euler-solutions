#!/usr/bin/python3

from timeit import default_timer

def main():
    start = default_timer()

    sum_ = 0

    for i in range(3, 1000):
        if i % 3 == 0 or i % 5 == 0:
            sum_ += i

    end = default_timer()

    print('Project Euler, Problem 1')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
