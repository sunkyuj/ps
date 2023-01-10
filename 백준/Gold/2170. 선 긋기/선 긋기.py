import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
l = [tuple(map(int, input().split())) for i in range(n)]
l.sort()

ans = 0
h, t = l[0]
for i in range(1, n):
    x, y = l[i]
    if h <= x <= t:
        t = max(t, y)
    else:
        ans += t - h
        h, t = x, y
ans += t - h
print(ans)