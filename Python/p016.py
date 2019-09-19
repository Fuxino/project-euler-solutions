#!/usr/bin/python3

from timeit import default_timer

def main():
    start = default_timer()

    res = str(2 ** 1000)

    sum_ = 0

    for i in range(len(res)):
        sum_ = sum_ + int(res[i])

    end = default_timer()

    print('Project Euler, Problem 16')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
