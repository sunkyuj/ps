import sys

sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()

T = int(input())

n = int(input())
A = list(map(int, input().split()))

m = int(input())
B = list(map(int, input().split()))

Asum = [0 for _ in range(n + 1)]
Bsum = [0 for _ in range(m + 1)]

for i in range(n):
    Asum[i] = Asum[i - 1] + A[i]

for i in range(m):
    Bsum[i] = Bsum[i - 1] + B[i]

Ad, Bd = {}, {}
for i in range(n):
    for j in range(i, n):
        x = Asum[j] - Asum[i - 1]
        Ad.setdefault(x, 0)
        Ad[x] += 1

for i in range(m):
    for j in range(i, m):
        x = Bsum[j] - Bsum[i - 1]
        Bd.setdefault(x, 0)
        Bd[x] += 1

ans = 0
for x, cnt in Ad.items():
    if T - x in Bd:
        ans += cnt * Bd[T - x]
print(ans)