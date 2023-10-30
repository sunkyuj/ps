from collections import deque

MAX = 10001
dydx = [(1, 0), (0, 1), (-1, 0), (0, -1)]  # v > ^ <
in_range = lambda y, x: 0 <= y < h and 0 <= x < w


w, h = map(int, input().split())
targets = []
board = [list(input()) for _ in range(h)]
dist = [[MAX for _ in range(w)] for _ in range(h)]
for i in range(h):
    for j in range(w):
        if board[i][j] == "C":
            targets.append((i, j))
            board[i][j] = "."

q = deque()
q.append((targets[0][0], targets[0][1], -1, [0, 1, 2, 3]))
dist[targets[0][0]][targets[0][1]] = 0

while q:
    y, x, d, dirs = q.popleft()
    if (y, x) == targets[1]:
        print(d)
        break

    if d > dist[y][x]:
        continue

    for k in dirs:
        dy, dx = dydx[k]
        ny, nx = y + dy, x + dx
        while in_range(ny, nx) and board[ny][nx] == ".":
            if dist[ny][nx] > dist[y][x] + 1:
                q.append((ny, nx, d + 1, [(k - 1) % 4, (k + 1) % 4]))
                dist[ny][nx] = dist[y][x] + 1
            ny += dy
            nx += dx
