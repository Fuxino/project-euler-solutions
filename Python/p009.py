#!/usr/bin/python3

from timeit import default_timer

def main():
    start = default_timer()

    found = 0

    m = 2

    while not found:
        for n in range(1, m):
            a = m * m - n * n
            b = 2 * m * n
            c = m * m + n * n

            if a + b + c == 1000:
                found = 1
                break

        m = m + 1

    end = default_timer()

    print('Project Euler, Problem 9')
    print('Answer: {}'.format(a * b * c))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
