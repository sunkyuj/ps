import sys

sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m

n = int(input())
t, p = [], []
for i in range(n):
    a, b = map(int, input().split())
    t.append(a)
    p.append(b)

ans = 0


def f(idx, sum):
    if idx == n:
        global ans
        ans = max(ans, sum)
        return
    if idx > n:
        return
    f(idx + t[idx], sum + p[idx])
    f(idx + 1, sum)


f(0, 0)
print(ans)
