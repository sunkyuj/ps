from collections import deque

n = int(input())
squares = [list(map(int, input().split())) for _ in range(n)]

dxdy = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # ^ > v <
in_range = lambda y, x: 0 <= y <= 1000 and 0 <= x <= 1000

board = [[[0, 0, 0, 0] for _ in range(1001)] for _ in range(1001)]
visit = [[0 for _ in range(1001)] for _ in range(1001)]
for sq in squares:
    for i in range(4):
        sq[i] += 500
    sx, sy, ex, ey = sq
    board[sx][sy][0] = 1
    board[sx][sy][1] = 1

    board[sx][ey][1] = 1
    board[sx][ey][2] = 1

    board[ex][sy][0] = 1
    board[ex][sy][3] = 1

    board[ex][ey][2] = 1
    board[ex][ey][3] = 1

    for j in range(sx + 1, ex):
        board[j][sy][1] = 1
        board[j][sy][3] = 1
        board[j][ey][1] = 1
        board[j][ey][3] = 1
    for i in range(sy + 1, ey):
        board[sx][i][0] = 1
        board[sx][i][2] = 1
        board[ex][i][0] = 1
        board[ex][i][2] = 1
union = 0


def bfs(sx, sy):
    global union
    union += 1
    q = deque()
    q.append((sx, sy))
    visit[sx][sy] = union

    while q:
        x, y = q.popleft()
        for dir in range(4):
            dx, dy = dxdy[dir]
            nx, ny = x + dx, y + dy
            if not in_range(ny, nx) or visit[nx][ny]:
                continue

            if board[x][y][dir]:
                q.append((nx, ny))
                visit[nx][ny] = union


for sq in squares:
    sx, sy, ex, ey = sq
    if not visit[sx][sy]:
        bfs(sx, sy)
ans = union
if visit[500][500]:
    ans -= 1
print(ans)
