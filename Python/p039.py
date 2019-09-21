#!/usr/bin/python3

from numpy import zeros

from timeit import default_timer

def main():
    start = default_timer()

    max_ = 0
    savedc = zeros(1000, int)

    for p in range(12, 1001):
        count = 0
        a = 0
        b = 0
        c = 0
        m = 2

        while m * m < p:
            for n in range(1, m):
                a = m * m - n * n
                b = 2 * m * n
                c = m * m + n * n

                if a + b + c == p and savedc[c] == 0:
                    savedc[c] = 1
                    count = count + 1

                i = 2
                tmpa = a
                tmpb = b
                tmpc = c

                while tmpa + tmpb + tmpc < p:
                    tmpa = a * i
                    tmpb = b * i
                    tmpc = c * i

                    if tmpa + tmpb + tmpc == p and savedc[tmpc] == 0:
                        savedc[tmpc] = 1
                        count = count + 1

                    i = i + 1

            m = m + 1

        if count > max_:
            max_ = count
            res = p

    end = default_timer()

    print('Project Euler, Problem 39')
    print('Answer: {}'.format(res))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
