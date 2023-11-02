from collections import deque

dydx = [(1, 0), (0, 1), (-1, 0), (0, -1)]  # v > ^ <
in_range = lambda y, x: 0 <= y < n and 0 <= x < n
MAX = 9999

n = int(input())
board = [list(input()) for _ in range(n)]
dp = [[[MAX, MAX, MAX, MAX] for _ in range(n)] for _ in range(n)]

door = []
for i in range(n):
    for j in range(n):
        if board[i][j] == "#":
            door.append((i, j))


sy, sx = door[0]
q = deque()
for d in range(4):  # 4 방향 처음에 다 넣어줌
    q.append((sy, sx, 0, d))
    dp[sy][sx][d] = 0

while q:
    y, x, cnt, d = q.popleft()
    # print(y, x, cnt, d)
    dy, dx = dydx[d]
    ny, nx = y + dy, x + dx
    while in_range(ny, nx) and board[ny][nx] != "*":
        dp[ny][nx][d] = min(dp[ny][nx][d], cnt)
        if (ny, nx) == door[1]:
            print(cnt)
            exit()
        if board[ny][nx] == "!":
            q.append((ny, nx, cnt + 1, (d + 1) % 4))
            q.append((ny, nx, cnt + 1, (d - 1) % 4))
        ny += dy
        nx += dx
