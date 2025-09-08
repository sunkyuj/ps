import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()
in_range = lambda z, y, x: 0 <= z < L and 0 <= y < R and 0 <= x < C
dzdydx = [[1, 0, 0], [-1, 0, 0], [0, 1, 0], [0, -1, 0], [0, 0, 1], [0, 0, -1]]
board = [[[0 for _ in range(30)] for _ in range(30)] for _ in range(30)]
visit = set()


def init(L, R, C):
    sz, sy, sx = 0, 0, 0
    visit.clear()
    for z in range(L):
        for y in range(R + 1):
            r = input()
            if r == "":
                continue
            for x in range(C):
                if r[x] == "S":
                    sz, sy, sx = z, y, x
                board[z][y][x] = r[x]
    return sz, sy, sx


def solve(sz, sy, sx):
    q = deque()
    q.append((sz, sy, sx, 0))
    visit.add((sz, sy, sx))

    while q:
        z, y, x, l = q.popleft()
        if board[z][y][x] == "E":
            return l

        for dz, dy, dx in dzdydx:
            nz, ny, nx = z + dz, y + dy, x + dx
            if not in_range(nz, ny, nx):
                continue
            if (nz, ny, nx) in visit or board[nz][ny][nx] == "#":
                continue
            q.append((nz, ny, nx, l + 1))
            visit.add((nz, ny, nx))

    return 0


while 1:
    L, R, C = map(int, input().split())
    if (L, R, C) == (0, 0, 0):
        break

    sz, sy, sx = init(L, R, C)
    ans = solve(sz, sy, sx)

    if ans == 0:
        print("Trapped!")
    else:
        print(f"Escaped in {ans} minute(s).")
