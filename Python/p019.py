#!/usr/bin/python3

import datetime

from timeit import default_timer

def main():
    start = default_timer()

    count = 0

    for year in range(1901, 2001):
        for month in range(1, 13):
            if datetime.datetime(year, month, 1).weekday() == 6:
                count = count + 1

    end = default_timer()

    print('Project Euler, Problem 19')
    print('Answer: {}'.format(count))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
