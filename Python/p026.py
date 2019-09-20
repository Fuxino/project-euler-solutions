#!/usr/bin/python3

from timeit import default_timer

def main():
    start = default_timer()

    max_ = 0

    for i in range(2, 1000):
        j = i

        while j % 2 == 0 and j > 1:
            j = j // 2

        while j % 5 == 0 and j > 1:
            j = j // 5

        k = 9

        if j == 1:
            n = 0
        else:
            n = 1
            div = j
            while k % div != 0:
                n = n + 1
                k = k * 10
                k = k + 9

            if n > max_:
                max_ = n
                max_n = i

    end = default_timer()

    print('Project Euler, Problem 26')
    print('Answer: {}'.format(max_n))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
