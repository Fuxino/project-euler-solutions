#!/usr/bin/python

# The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3). 
# In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.
#
# Find the smallest cube for which exactly five permutations of its digits are cube.

from timeit import default_timer

from numpy import zeros


def main():
    start = default_timer()

    N = 10000

    cubes = zeros(N, int)

#   Calculate i^3 for all i smaller than 10000
    for i in range(N):
        cubes[i] = i * i * i

#   For each cube, check if there are four other cubes which are also
#   a permutation of the first cube.
    for i in range(N-5):
        count = 1

#       Stop when the limit has been reached, when 5 values have been found or
#       when j^3 has more digits than i^3 (if they don't have the same digits,
#       they can't be permutations).
        j = i + 1

        while j < N and len(str(cubes[j])) == len(str(cubes[i])):
            if ''.join(sorted(str(cubes[i]))) == ''.join(sorted(str(cubes[j]))):
                count = count + 1

            if count == 5:
                break

            j = j + 1

        if count == 5:
            break

    end = default_timer()

    print('Project Euler, Problem 62')
    print(f'Answer: {cubes[i]}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
