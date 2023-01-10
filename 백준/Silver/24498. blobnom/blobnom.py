import sys

sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m


n = int(input())
h = list(map(int, input().split()))


ans = 0
for i in range(1, n - 1):
    add = min(h[i - 1], h[i + 1])
    ans = max(ans, h[i] + add)
print(max(h[:] + [ans]))
