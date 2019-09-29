#!/usr/bin/python3

# Consider the following "magic" 3-gon ring, filled with the numbers 1 to 6, and each line adding to nine.
#
#         4
#          \
#           \
#            3
#           /  \
#          /    \
#         1------2------6
#        /
#       /
#      5
#
# Working clockwise, and starting from the group of three with the numerically lowest external node (4,3,2 in this example),
# each solution can be described uniquely. For example, the above solution can be described by the set: 4,3,2; 6,2,1; 5,1,3.
#
# It is possible to complete the ring with four different totals: 9, 10, 11, and 12. There are eight solutions in total.
#
# Total	Solution Set
# 9	4,2,3; 5,3,1; 6,1,2
# 9	4,3,2; 6,2,1; 5,1,3
# 10	2,3,5; 4,5,1; 6,1,3
# 10	2,5,3; 6,3,1; 4,1,5
# 11	1,4,6; 3,6,2; 5,2,4
# 11	1,6,4; 5,4,2; 3,2,6
# 12	1,5,6; 2,6,4; 3,4,5
# 12	1,6,5; 3,5,4; 2,4,6
#
# By concatenating each group it is possible to form 9-digit strings; the maximum string for a 3-gon ring is 432621513.
#
# Using the numbers 1 to 10, and depending on arrangements, it is possible to form 16- and 17-digit strings. What is the maximum 16-digit string
# for a "magic" 5-gon ring?
#
#             O
#              \
#               O
#             /  \   O
#            /    \ /
#           O      O
#          / \    /
#         O   O--O---O
#              \
#               O
#

from itertools import permutations

from timeit import default_timer

# Function to evaluate the ring. The ring is represented as a vector of 2*n elements,
# the first n elements represent the external nodes of the ring, the next n elements
# represent the internal ring.
def eval_ring(ring, n):
    for i in range(1, n):
#       We need to start from the lowest external node, so if
#       the first element in the vector is not the lowest of
#       the first n elements (the external elements), the configuration
#       is not a valid one.
        if ring[i] < ring[0]:
            return None

    res = [0] * 3 * n

#   Each group of three must have the same value.
    magic_val = ring[0] + ring[n] + ring[n+1]

    j = 0

    for i in range(n):
#       We need to find the maximum 16-digit string, this is
#       possible only if the element "10" is used only once,
#       i.e. if it's one of the external nodes.
        if ring[n+i] == 10 or ring[n+(i+1)%n] == 10:
            return None

#       Check that the value of the current three-element group
#       is the "magic" value.
        val = ring[i] + ring[n+i] + ring[n+(i+1)%n]

        if val != magic_val :
            return None

#       Save the current element group in the result string.
        res[j] = ring[i]
        res[j+1] = ring[n+i]
        res[j+2] = ring[n+(i+1)%n]

        j = j + 3

    return res

def list_to_int(l):
    if l == None:
        return 0

    res = 0
    k = 0

    for i in reversed(l):
        res = res + i * 10 ** k

        if i >= 10:
            k = k + 2
        else:
            k = k + 1

    return res

def main():
    start = default_timer()

#   Generate all possible permutations, for each one check if
#   it's a possible solution for the ring and save the maximum
    rings = list(permutations(list(range(1, 11))))
    max_ = 0
    n = None

    for ring in rings:
        eval_ = eval_ring(ring, 5);
   
#       Convert the list into an integer number.
        n = list_to_int(eval_)

        if n > max_:
            max_ = n

    end = default_timer()

    print('Project Euler, Problem 68')
    print('Answer: {}'.format(max_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
