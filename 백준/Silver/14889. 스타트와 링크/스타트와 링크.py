import sys
import itertools

sys.setrecursionlimit(10**8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m

n = int(input())

board = [list(map(int, input().split())) for _ in range(n)]
all = set(range(n))
ans = 100000000
for comb in itertools.combinations(range(n), n // 2): 
    comb = set(comb)
    others = all - comb

    a, b = 0, 0
    for i in comb:
        for j in comb:
            a += board[i][j]
    for i in others:
        for j in others:
            b += board[i][j]
    ans = min(ans, abs(a - b))
print(ans)
