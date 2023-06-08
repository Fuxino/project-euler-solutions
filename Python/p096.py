# Su Doku (Japanese meaning number place) is the name given to a popular puzzle concept. Its origin is unclear,
# but credit must be attributed to Leonhard Euler who invented a similar, and much more difficult, puzzle idea called Latin Squares.
# The objective of Su Doku puzzles, however, is to replace the blanks (or zeros) in a 9 by 9 grid in such that each row, column,
# and 3 by 3 box contains each of the digits 1 to 9. Below is an example of a typical starting puzzle grid and its solution grid.
#
#    0 0 3  0 2 0  6 0 0        4 8 3  9 2 1  6 5 7
#    9 0 0  3 0 5  0 0 1        9 6 7  3 4 5  8 2 1
#    0 0 1  8 0 6  4 0 0        2 5 1  8 7 6  4 9 3
#
#    0 0 8  1 0 2  9 0 0        5 4 8  1 3 2  9 7 6
#    7 0 0  0 0 0  0 0 8        7 2 9  5 6 4  1 3 8
#    0 0 6  7 0 8  2 0 0        1 3 6  7 9 8  2 4 5
#
#    0 0 2  6 0 9  5 0 0        3 7 2  6 8 9  5 1 4
#    8 0 0  2 0 3  0 0 9        8 1 4  2 5 3  7 6 9
#    0 0 5  0 1 0  3 0 0        6 9 5  4 1 7  3 8 2
#
# A well constructed Su Doku puzzle has a unique solution and can be solved by logic, although it may be necessary to employ
# "guess and test" methods in order to eliminate options (there is much contested opinion over this). The complexity of the search
# determines the difficulty of the puzzle; the example above is considered easy because it can be solved by straight forward direct deduction.
#
# The 6K text file, sudoku.txt, contains fifty different Su Doku puzzles ranging in difficulty, but all with unique solutions
# (the first puzzle in the file is the example above).
#
# By solving all fifty puzzles find the sum of the 3-digit numbers found in the top left corner of each solution grid;
# for example, 483 is the 3-digit number found in the top left corner of the solution grid above.

import sys
from itertools import islice

from projecteuler import timing


def check(sudoku, i, j, n):
    for k in range(9):
        if k != j and sudoku[i][k] == n:
            return False

        if k != i and sudoku[k][j] == n:
            return False

    ii = 3 * (i // 3)
    jj = 3 * (j // 3)

    for k in range(3):
        for w in range(3):
            if ii + k != i and jj + w != j and sudoku[ii+k][jj+w] == n:
                return False

    return True


def solve_recursive(sudoku, step):
    if step == 81:
        return True

    i = step // 9
    j = step % 9

    if sudoku[i][j] != 0:
        if solve_recursive(sudoku, step + 1):
            return True
    else:
        for k in range(1, 10):
            sudoku[i][j] = k

            if check(sudoku, i, j, k):
                if solve_recursive(sudoku, step + 1):
                    return True

                sudoku[i][j] = 0

        sudoku[i][j] = 0

    return False


def line_complete(sudoku, i):
    for n in range(9):
        if sudoku[i][n] == 0:
            return False

    return True


def column_complete(sudoku, j):
    for n in range(9):
        if sudoku[n][j] == 0:
            return False

    return True


def solve_sudoku(sudoku):
    for w in range(4):
        for i in range(9):
            for j in range(9):
                if sudoku[i][j] == 0:
                    count = 0

                    for k in range(1, 10):
                        if count >= 2:
                            break

                        sudoku[i][j] = k

                        if check(sudoku, i, j, k):
                            count += 1
                            val = k

                    if count == 1:
                        sudoku[i][j] = val
                    else:
                        sudoku[i][j] = 0

        for i in range(9):
            for k in range(1, 10):
                if line_complete(sudoku, i):
                    break

                count = 0

                for j in range(9):
                    if count >= 2:
                        break

                    if sudoku[i][j] == 0:
                        sudoku[i][j] = k

                        if check(sudoku, i, j, k):
                            count += 1
                            val = j

                        sudoku[i][j] = 0

                if count == 1:
                    sudoku[i][val] = k

        for j in range(9):
            for k in range(1, 10):
                if column_complete(sudoku, j):
                    break

                count = 0

                for i in range(9):
                    if count >= 2:
                        break

                    if sudoku[i][j] == 0:
                        sudoku[i][j] = k

                        if check(sudoku, i, j, k):
                            count += 1
                            val = i

                        sudoku[i][j] = 0

                if count == 1:
                    sudoku[val][j] = k

    return solve_recursive(sudoku, 0)


@timing
def p096():
    try:
        with open('p096_sudoku.txt', 'r', encoding='utf-8') as fp:
            sudokus = fp.readlines()
    except FileNotFoundError:
        print('Error while opening file p096_sudoku.txt')
        sys.exit(1)

    sum_ = 0
    start = 0
    stop = 10

    while stop <= len(sudokus):
        sudoku = islice(sudokus, start, stop)
        sudoku = [line.strip() for line in list(sudoku)[1:]]
        sudoku = [list(line) for line in sudoku]

        for i, _ in enumerate(sudoku):
            sudoku[i] = [int(n) for n in sudoku[i]]

        if not solve_sudoku(sudoku):
            print('Bad sudoku grid')

            sys.exit(1)

        partial = int(sudoku[0][0]) * 100 + int(sudoku[0][1]) * 10 + int(sudoku[0][2])
        sum_ += partial

        start += 10
        stop += 10

    print('Project Euler, Problem 96')
    print(f'Answer: {sum_}')


if __name__ == '__main__':
    p096()
