#!/usr/bin/python3

from math import sqrt, floor

from numpy import ndarray, zeros

def is_prime(num):
    if num < 4:
        return num == 2 or num == 3

    if num % 2 == 0 or num % 3 == 0:
        return False

    limit = floor(sqrt(num)) + 1

    for i in range(5, limit, 6):
        if num % i == 0 or num % (i + 2) == 0:
            return False

    return True

def gcd(a, b):
    if b == 0:
        return a

    return gcd(b, a%b)

def lcm(a, b):
    return a * b // gcd(a, b)

def lcmm(values, n):
    if n == 2:
        return lcm(values[0], values[1])

    value = values[0]

    for i in range(1, n):
        return lcm(value, lcmm(values[i:], n-1))

def sieve(n):
    primes = ndarray((n,), int)

    primes[0] = 0
    primes[1] = 0
    primes[2] = 1
    primes[3] = 1

    for i in range(4, n, 2):
        primes[i] = 0
        primes[i+1] = 1

    limit = floor(sqrt(n))

    for i in range(3, limit, 2):
        if primes[i]:
            for j in range(i * i, n, 2 * i):
                primes[j] = 0

    return primes

def count_divisors(n):
    count = 0
    limit = floor(sqrt(n))

    for i in range(1, limit):
        if n % i == 0:
            count = count + 2

        if n == limit * limit:
            count = count - 1

    return count

def is_palindrome(num, base):
    reverse = 0

    tmp = num

    while tmp > 0:
        reverse = reverse * base
        reverse = reverse + tmp % base
        tmp = tmp // base

    if num == reverse:
        return True

    return False

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
    i = (sqrt(24*n+1) + 1) / 6

    return i.is_integer()

