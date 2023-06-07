#!/usr/bin/env python3

# You are given the following information, but you may prefer to do some research for yourself.
#
# 1 Jan 1900 was a Monday.
# Thirty days has September,
# April, June and November.
# All the rest have thirty-one,
# Saving February alone,
# Which has twenty-eight, rain or shine.
# And on leap years, twenty-nine.
# A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
#
# How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

import datetime

from projecteuler import timing


@timing
def p019():
    count = 0

    # Use the datetime library to find out which first day of the month is a Sunday
    for year in range(1901, 2001):
        for month in range(1, 13):
            if datetime.datetime(year, month, 1).weekday() == 6:
                count = count + 1

    print('Project Euler, Problem 19')
    print(f'Answer: {count}')


if __name__ == '__main__':
    p019()
