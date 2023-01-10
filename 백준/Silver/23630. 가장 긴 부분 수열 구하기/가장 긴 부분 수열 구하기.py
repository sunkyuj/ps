# n = int(input())
# a = list(set(map(int, input().split())))

import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
sequence = list(map(int, input().split()))
bit_count = [0] * 32


def calc_bit(a):
    temp = a
    n = 0
    while temp > 0:
        bit_count[n] += temp % 2
        temp = temp // 2
        n += 1


for item in sequence:
    calc_bit(item)

print(max(bit_count))
