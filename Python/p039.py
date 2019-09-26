#!/usr/bin/python3

# If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
#
# {20,48,52}, {24,45,51}, {30,40,50}
#
# For which value of p ≤ 1000, is the number of solutions maximised?

from numpy import zeros

from timeit import default_timer

def main():
    start = default_timer()

    max_ = 0
    savedc = zeros(1000, int)

#   Start with p=12 (the smallest pythagorean triplet is (3,4,5) and 3+4+5=12.
    for p in range(12, 1001):
        count = 0
        a = 0
        b = 0
        c = 0
        m = 2

#       Generate pythagorean triplets.
        while m * m < p:
            for n in range(1, m):
                a = m * m - n * n
                b = 2 * m * n
                c = m * m + n * n

#               Increase counter if a+b+c=p and the triplet is new,
#               then save the value of c to avoid counting the same
#               triplet more than once.
                if a + b + c == p and savedc[c] == 0:
                    savedc[c] = 1
                    count = count + 1

                i = 2
                tmpa = a
                tmpb = b
                tmpc = c

#               Check all the triplets obtained multiplying a, b and c
#               for integer numbers, until the perimeters exceeds p.
                while tmpa + tmpb + tmpc < p:
                    tmpa = a * i
                    tmpb = b * i
                    tmpc = c * i

#                   Increase counter if the new a, b and c give a perimeter=p.
                    if tmpa + tmpb + tmpc == p and savedc[tmpc] == 0:
                        savedc[tmpc] = 1
                        count = count + 1

                    i = i + 1

            m = m + 1

#       If the current value is greater than the maximum,
#       save the new maximum and the value of p.
        if count > max_:
            max_ = count
            res = p

    end = default_timer()

    print('Project Euler, Problem 39')
    print('Answer: {}'.format(res))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
