#!/usr/bin/python3

from timeit import default_timer

def main():
    start = default_timer()

    n_letters = [[3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8],\
                [60, 60, 50, 50, 50, 70, 60, 60],\
                [1300, 1300, 1500, 1400, 1400, 1300, 1500, 1500, 1400],\
                [11]]

    sum_ = 0

    for i in range(19):
        sum_ = sum_ + n_letters[0][i]

    for i in range(8):
        for j in range(9):
            n_letters[1][i] = n_letters[1][i] + n_letters[0][j]
        sum_ = sum_ + n_letters[1][i]

    for i in range(9):
        for j in range(19):
            n_letters[2][i] = n_letters[2][i] + n_letters[0][j]
        for j in range(8):
            n_letters[2][i] = n_letters[2][i] + n_letters[1][j]
        sum_ = sum_ + n_letters[2][i] - 3

    sum_ = sum_ + n_letters[3][0]

    end = default_timer()

    print('Project Euler, Problem 17')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
