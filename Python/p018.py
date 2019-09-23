#!/usr/bin/python3

from timeit import default_timer
from projecteuler import find_max_path

def main():
    start = default_timer()

    try:
        fp = open('triang.txt', 'r')
    except:
        print('Error while opening file {}'.format('triang.txt'))
        exit(1)

    triang = list()

    for line in fp:
        triang.append(line.strip('\n').split())

    fp.close()

    l = len(triang)

    for i in range(l):
        triang[i] = list(map(int, triang[i]))

    max_ = find_max_path(triang, 15)

    end = default_timer()

    print('Project Euler, Problem 18')
    print('Answer: {}'.format(max_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
