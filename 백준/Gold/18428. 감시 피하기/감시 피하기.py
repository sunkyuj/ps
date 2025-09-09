import sys

sys.setrecursionlimit(10**5)
input = lambda: sys.stdin.readline().rstrip()
in_range = lambda y, x: 0 <= y < N and 0 <= x < N
dydx = [(0, 1), (0, -1), (1, 0), (-1, 0)]

N = int(input())
board = [list(input().split()) for _ in range(N)]

t_loc = set()
for i in range(N):
    for j in range(N):
        if board[i][j] == "T":
            t_loc.add((i, j))


def teacher_can_see(y, x, objs):
    for ny in range(y + 1, N):
        if board[ny][x] == "S":
            return True
        if (ny, x) in objs:
            break
    for nx in range(x + 1, N):
        if board[y][nx] == "S":
            return True
        if (y, nx) in objs:
            break
    for ny in range(y - 1, -1, -1):
        if board[ny][x] == "S":
            return True
        if (ny, x) in objs:
            break
    for nx in range(x - 1, -1, -1):
        if board[y][nx] == "S":
            return True
        if (y, nx) in objs:
            break

    return False


def check(objs):
    for y, x in t_loc:
        if teacher_can_see(y, x, objs):
            return False
    return True


def solve():
    for i in range(N**2):
        y1, x1 = i // N, i % N
        if board[y1][x1] != "X":
            continue
        for j in range(i + 1, N**2):
            y2, x2 = j // N, j % N
            if board[y2][x2] != "X":
                continue
            for k in range(j + 1, N**2):
                y3, x3 = k // N, k % N
                if board[y3][x3] != "X":
                    continue
                objs = {(y1, x1), (y2, x2), (y3, x3)}
                # 놓는 위치는 X 여야만함
                if check(objs):
                    return True
    return False


print("YES" if solve() else "NO")
