#!/usr/bin/python

# A common security method used for online banking is to ask the user for three random characters from a passcode.
# For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.
#
# The text file, p079_keylog.txt, contains fifty successful login attempts.
#
# Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible
# secret passcode of unknown length.

import sys
from itertools import permutations
from timeit import default_timer


def check_passcode(passcode, len_, logins, n):
#   For every login attempt, check if all the digits appear in the
#   passcode in the correct order. Return 0 if a login attempt
#   incompatible with the current passcode is found.
    for i in range(n):
        k = 0
        for j in range(len_):
            if passcode[j] == int(logins[i][k]):
                k = k + 1

                if k == 3:
                    break

        if k < 3:
            return 0

    return 1


def main():
    start = default_timer()

    try:
        with open('p079_keylog.txt', 'r', encoding='utf-8') as fp:
            logins = fp.readlines()
    except FileNotFoundError:
        print('Error while opening file p079_keylog.txt')
        sys.exit(1)

    digits = [0] * 10
    passcode_digits = [0] * 10

    for i in logins:
        keylog = int(i)

#       Check which digits are present in the login attempts.
        while True:
            digits[keylog % 10] = digits[keylog % 10] + 1
            keylog = keylog // 10

            if keylog == 0:
                break

    j = 0
    for i in range(10):
#       To generate the passcode, only use the digits present in the
#       login attempts.
        if digits[i] > 0:
            passcode_digits[j] = i
            j = j + 1

    found = 0
    len_ = 4

    while not found:
        passcode = [0] * len_

#       For the current length, generate the first passcode with the
#       digits in order.
        for i in range(len_):
            passcode[i] = passcode_digits[i]

#       Check if the passcode is compatible with the login attempts.
        if check_passcode(passcode, len_, logins, 50):
            found = 1
            break

#       For the given length, check every permutation until the correct
#       passcode has been found, or all the permutations have been tried.
        passcodes = permutations(passcode, len_)

        for i in passcodes:
            if check_passcode(i, len_, logins, 50):
                found = 1
                res = ''.join(map(str, i))
                break

#       If the passcode has not yet been found, try a longer passcode.
        len_ = len_ + 1

    end = default_timer()

    print('Project Euler, Problem 79')
    print(f'Answer: {res}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
