import sys

input = lambda: sys.stdin.readline().rstrip()

f = [0 for _ in range(1000001)]
for i in range(1, 1000001):
    for j in range(i, 1000001, i):
        f[j] += i

g = [0] * 1000001
for i in range(1, 1000001):
    g[i] = g[i - 1] + f[i]

for _ in range(int(input())):  # 10만
    n = int(input())  # 100만
    # f(n) = 약수의 합
    # g(n) = f(1) + f(2) + ... + f(n-1) + f(n)
    print(g[n])
