import sys
from collections import deque

#sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
in_range = lambda y, x: 0 <= y < n and 0 <= x < m
dy = [1, 0, -1, 0]
dx = [0, -1, 0, 1]

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

vir = {}
v = [0, deque(), deque()]
cnt1, cnt2, cnt3 = 1, 1, 0

for i in range(n):
    for j in range(m):
        if board[i][j] >= 1:
            v[board[i][j]].append((i, j))


while v[1] or v[2]:
    tmp1, tmp2 = set(), set()

    while v[1]:
        y, x = v[1].popleft()
        for k in range(4):
            ny, nx = y + dy[k], x + dx[k]
            if in_range(ny, nx) and board[ny][nx] == 0:
                tmp1.add((ny, nx))
    while v[2]:
        y, x = v[2].popleft()
        for k in range(4):
            ny, nx = y + dy[k], x + dx[k]
            if in_range(ny, nx) and board[ny][nx] == 0:
                tmp2.add((ny, nx))

    tmp3 = tmp1 & tmp2
    for y, x in tmp3:
        board[y][x] = 3
        cnt3 += 1

    for y, x in tmp1 - tmp3:
        board[y][x] = 1
        v[1].append((y, x))
        cnt1 += 1

    for y, x in tmp2 - tmp3:
        board[y][x] = 2
        v[2].append((y, x))
        cnt2 += 1

print(cnt1, cnt2, cnt3)
