#!/usr/bin/python3

from math import sqrt, floor, gcd

from numpy import ndarray, zeros

def is_prime(num):
    if num < 4:
#       If num is 2 or 3 then it's prime.
        return num == 2 or num == 3

#   If num is divisible by 2 or 3 then it's not prime.
    if num % 2 == 0 or num % 3 == 0:
        return False
#   Any number can have only one prime factor greater than its
#   square root. If we reach the square root and we haven't found
#   any smaller prime factors, then the number is prime.
    limit = floor(sqrt(num)) + 1

#   Every prime other than 2 and 3 is in the form 6k+1 or 6k-1.
#   If I check all those value no prime factors of the number
#   will be missed. If a factor is found, the number is not prime
#   and the function returns 0.
    for i in range(5, limit, 6):
        if num % i == 0 or num % (i + 2) == 0:
            return False

#   If no factor is found up to the square root of num, num is prime.
    return True

def is_palindrome(num, base):
    reverse = 0

    tmp = num

#   Start with reverse=0, get the rightmost digit of the number using
#   modulo operation (num modulo base), add it to reverse. Remove the
#   rightmost digit from num dividing num by the base, shift the reverse left
#   multiplying by the base, repeat until all digits have been inserted
#   in reverse order.
    while tmp > 0:
        reverse = reverse * base
        reverse = reverse + tmp % base
        tmp = tmp // base

#   If the reversed number is equal to the original one, then it's palindrome.
    if num == reverse:
        return True

    return False
# Least common multiple algorithm using the greatest common divisor.
def lcm(a, b):
    return a * b // gcd(a, b)

# Recursive function to calculate the least common multiple of more than 2 numbers.
def lcmm(values, n):
#   If there are only two numbers, use the lcm function to calculate the lcm.
    if n == 2:
        return lcm(values[0], values[1])

    value = values[0]

#   Recursively calculate lcm(a, b, c, ..., n) = lcm(a, lcm(b, c, ..., n)).
    return lcm(value, lcmm(values[1:], n-1))

# Function implementing the Sieve or Eratosthenes to generate
# primes up to a certain number.
def sieve(n):
    primes = ndarray((n,), int)

#   0 and 1 are not prime, 2 and 3 are prime.
    primes[0] = 0
    primes[1] = 0
    primes[2] = 1
    primes[3] = 1

#   Cross out (set to 0) all even numbers and set the odd numbers to 1 (possible prime).
    for i in range(4, n -1, 2):
        primes[i] = 0
        primes[i+1] = 1

#   If i is prime, all multiples of i smaller than i*i have already been crossed out.
#   if i=sqrt(n), all multiples of i up to n (the target) have been crossed out. So
#   there is no need check i>sqrt(n).
    limit = floor(sqrt(n))

    for i in range(3, limit, 2):
#       Find the next number not crossed out, which is prime.
        if primes[i] == 1:
#           Cross out all multiples of i, starting with i*i because any smaller multiple
#           of i has a smaller prime factor and has already been crossed out. Also, since
#           i is odd, i*i+i is even and has already been crossed out, so multiples are
#           crossed out with steps of 2*i.
            for j in range(i * i, n, 2 * i):
                primes[j] = 0

    return primes

def count_divisors(n):
    count = 0
#   For every divisor below the square root of n, there is a corresponding one
#   above the square root, so it's sufficient to check up to the square root of n
#   and count every divisor twice. If n is a perfect square, the last divisor is
#   wrongly counted twice and must be corrected.
    limit = floor(sqrt(n))

    for i in range(1, limit):
        if n % i == 0:
            count = count + 2

    if n == limit * limit:
        count = count - 1

    return count

def find_max_path(triang, n):
#   Start from the second to last row and go up.
    for i in range(n-2, -1, -1):
#       For each element in the row, check the two adjacent elements
#       in the row below and sum the larger one to it. At the end,
#       the element at the top will contain the value of the maximum path.
        for j in range(0, i+1):
            if triang[i+1][j] > triang[i+1][j+1]:
                triang[i][j] = triang[i][j] + triang[i+1][j]
            else:
                triang[i][j] = triang[i][j] + triang[i+1][j+1]

    return triang[0][0]

def sum_of_divisors(n):
#   For each divisor of n smaller than the square root of n,
#   there is another one larger than the square root. If i is
#   a divisor of n, so is n/i. Checking divisors i up to square
#   root of n and adding both i and n/i is sufficient to sum
#   all divisors.
    limit = floor(sqrt(n)) + 1

    sum_ = 1

    for i in range(2, limit):
        if n % i == 0:
            sum_ = sum_ + i
#           If n is a perfect square, i=limit is a divisor and
#           has to be counted only once.
            if n != i * i:
                sum_ = sum_ + n // i

    return sum_

def is_pandigital(value, n):
    i = 0
    digits = zeros(n + 1, int)

    while i < n and value > 0:
        digit = value % 10
        if digit > n:
            return False
        digits[digit] = digits[digit] + 1
        value = value // 10
        i = i + 1

    if i < n or value > 0:
        return False

    if digits[0] != 0:
        return False

    for i in range(1, n+1):
        if digits[i] != 1:
            return False
        i = i + 1

    return True

def is_pentagonal(n):
#   A number n is pentagonal if p=(sqrt(24n+1)+1)/6 is an integer.
#   In this case, n is the pth pentagonal number.
    i = (sqrt(24*n+1) + 1) / 6

    return i.is_integer()

