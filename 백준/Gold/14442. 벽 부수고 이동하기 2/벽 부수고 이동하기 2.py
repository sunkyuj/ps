from collections import deque
import sys

input = lambda: sys.stdin.readline().rstrip()
n, m, k = map(int, input().split())
board = [list(map(int, input())) for _ in range(n)]

dydx = [(1, 0), (0, 1), (-1, 0), (0, -1)]
in_range = lambda y, x: 0 <= y < n and 0 <= x < m
visit = [[[0] * (k + 1) for _ in range(m)] for _ in range(n)]


q = deque()
q.append((0, 0, 1, 0))  # y,x,l,bs
visit[0][0][0] = 1


def never_visited(y, x, bs):
    for i in range(bs + 1):
        if visit[y][x][i]:
            return 0
    return 1


def visit_check(y, x, bs):
    for i in range(bs, k + 1):
        visit[y][x][i] = 1


while q:
    y, x, l, bs = q.popleft()
    if (y, x) == (n - 1, m - 1):
        print(l)
        exit()

    for dy, dx in dydx:
        ny, nx = y + dy, x + dx
        if not in_range(ny, nx) or visit[ny][nx][bs]:
            continue

        # 빈 칸인 경우
        if board[ny][nx] == 0:  # space
            q.append((ny, nx, l + 1, bs))
            visit_check(ny, nx, bs)
        # 벽 부수는 경우
        if board[ny][nx] and bs < k and not visit[ny][nx][bs + 1]:
            q.append((ny, nx, l + 1, bs + 1))
            visit_check(ny, nx, bs + 1)

print(-1)
