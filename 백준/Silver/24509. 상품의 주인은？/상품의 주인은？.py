import sys

# sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m

n = int(input())
s = [list(map(int, input().split())) for _ in range(n)]

l = [None, [], [], [], []]
dup = set()

for j in range(1, 5):
    for i in range(n):
        l[j].append((s[i][j], -s[i][0]))

    l[j].sort(reverse=True)
    for k in range(n):
        if l[j][k][1] not in dup:
            dup.add(l[j][k][1])
            print(-l[j][k][1], end=" ")
            break
