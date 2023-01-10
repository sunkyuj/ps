import sys

sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m

n = int(input())
p = [tuple(map(int, input().split())) for _ in range(n)]
p.sort(key=lambda x: (x[1], x[0]))
for i in range(n):
    print(p[i][0], p[i][1])
