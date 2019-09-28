#!/usr/bin/python

# The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.
#
# How many n-digit positive integers exist which are also an nth power?

from timeit import default_timer

def main():
    start = default_timer()

    i = 1
    count = 0
    finished = 0

    while not finished:
#       When j=10, j^i will have i+1 digits (e.g. if i=3, 10^3=1000).
        for j in range(1, 10):
            p = j ** i

            if len(str(p)) == i:
                count = count + 1

#       When 9^i has less than i digits, all the numbers have been found.
        if len(str(p)) < i:
            finished = 1

        i = i + 1

    end = default_timer()

    print('Project Euler, Problem 63')
    print('Answer: {}'.format(count))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
