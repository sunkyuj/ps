import sys

input = lambda: sys.stdin.readline().rstrip()

f = [0 for _ in range(1000001)]
for i in range(1, 1000001):
    for j in range(i, 1000001, i):
        f[j] += i

g = [0] * 1000001
for i in range(1, 1000001):
    g[i] = g[i - 1] + f[i]

n = int(input())
print(g[n])