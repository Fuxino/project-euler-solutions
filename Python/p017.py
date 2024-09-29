#!/usr/bin/env python3

# If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
#
# If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
#
# NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen)
# contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

from projecteuler import timing


@timing
def p017() -> None:
    # First list contains number of letters for numbers from 1 to 19,
    # the second letters for "twenty", "thirty", ..., "ninety",
    # the third letters for "one hundred and", "two hundred and", ..., "nine hundre and",
    # the last one-element one the number of letters of 1000
    n_letters = [[3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8],
                 [6, 6, 5, 5, 5, 7, 6, 6],
                 [13, 13, 15, 14, 14, 13, 15, 15, 14],
                 [11]]

    sum_ = 0

    # Sum the letters of the first 19 numbers.
    for i in range(19):
        sum_ = sum_ + n_letters[0][i]

    # Add the letters of the numbers from 20 to 99.
    for i in range(8):
        # "Twenty", "thirty", ... "ninety" are used ten times each
        # (e.g. "twenty", "twenty one", "twenty two", ..., "twenty nine").
        n_letters[1][i] = n_letters[1][i] * 10

        # Add "one", "two", ..., "nine".
        for j in range(9):
            n_letters[1][i] = n_letters[1][i] + n_letters[0][j]

        sum_ = sum_ + n_letters[1][i]

    # Add the letters of the numbers from 100 to 999.
    for i in range(9):
        # "One hundred and", "two hundred and",... are used 100 times each.
        n_letters[2][i] = n_letters[2][i] * 100

        # Add "one" to "nineteen".
        for j in range(19):
            n_letters[2][i] = n_letters[2][i] + n_letters[0][j]
        # Add "twenty" to "ninety nine", previously calculated.
        for j in range(8):
            n_letters[2][i] = n_letters[2][i] + n_letters[1][j]
        # "One hundred", "two hundred", ... don't have the "and", so remove
        # three letters for each of them.
        sum_ = sum_ + n_letters[2][i] - 3

    # Add "one thousand".
    sum_ = sum_ + n_letters[3][0]

    print('Project Euler, Problem 17')
    print(f'Answer: {sum_}')


if __name__ == '__main__':
    p017()
