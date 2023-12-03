from collections import deque

MAX = 9999
n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

dydx = [(0, 1), (1, 0), (0, -1), (-1, 0), (1, 1), (-1, 1), (1, -1), (-1, -1)]
dist = [[MAX] * m for _ in range(n)]


def bfs(i, j):
    q = deque()
    q.append((i, j, 0))
    dist[i][j] = 0
    while q:
        y, x, d = q.popleft()
        if d > dist[y][x]:
            continue
        for dy, dx in dydx:
            ny, nx = y + dy, x + dx
            if 0 <= ny < n and 0 <= nx < m and board[ny][nx] == 0 and dist[ny][nx] > d + 1:
                q.append((ny, nx, d + 1))
                dist[ny][nx] = d + 1

    return


for i in range(n):
    for j in range(m):
        if board[i][j]:
            bfs(i, j)
            
ans = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == 0:
            ans = max(dist[i][j], ans)
print(ans)
