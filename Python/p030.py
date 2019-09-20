#!/usr/bin/python3

from timeit import default_timer

def main():
    start = default_timer()

    tot = 0

    for i in range(10, 354295):
        j = i
        sum_ = 0

        while j > 0:
            digit = j % 10
            sum_ = sum_ + digit ** 5
            j = j // 10

        if sum_ == i:
            tot = tot + i

    end = default_timer()

    print('Project Euler, Problem 30')
    print('Answer: {}'.format(tot))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
