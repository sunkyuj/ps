import sys

sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m

n, k = map(int, input().split())
a = list(map(int, input().split()))
s = [0 for _ in range(n + 1)]

for i in range(n):
    s[i] = s[i - 1] + a[i]

ans = 0
for i in range(n):
    if i + k - 1 < n:
        ans = max(ans, s[i + k - 1] - s[i - 1])
    else:
        ans = max(ans, s[n - 1] - s[i - 1] + s[i + k - 1 - n])
print(ans)
