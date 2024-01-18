from collections import deque

n, m = map(int, input().split())
in_range = lambda y, x: 0 <= y < n and 0 <= x < m
dydx = [(1, 0), (0, 1), (-1, 0), (0, -1)]

sy, sx, gy, gx = map(int, input().split())
sy, sx, gy, gx = sy - 1, sx - 1, gy - 1, gx - 1
board = [list(input()) for _ in range(n)]
for i in range(n):
    for j in range(m):
        if board[i][j] == "#":
            board[i][j] = "1"
        elif board[i][j] == "*":
            board[i][j] = "0"
    board[i] = list(map(int, board[i]))
visit = [[0] * m for _ in range(n)]


def bfs(i, j):
    if visit[i][j]:
        return set()

    destroy = set()
    q = deque()
    q.append((i, j))
    visit[i][j] = 1
    while q:
        y, x = q.popleft()
        for dy, dx in dydx:
            ny, nx = y + dy, x + dx
            if not in_range(ny, nx) or visit[ny][nx]:
                continue
            if board[ny][nx] == 0:
                q.append((ny, nx))
                visit[ny][nx] = 1
            else:
                destroy.add((ny, nx))
    return destroy


ans = 0
start = {(sy, sx)}
while board[gy][gx]:
    ans += 1
    new_start = set()
    for sy, sx in start:
        new_start.update(bfs(sy, sx))
    for y, x in new_start:
        board[y][x] = 0
    start = new_start

print(ans)
