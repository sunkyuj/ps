from collections import deque

q = deque()
dy, dx = [1, -1, 0, 0], [0, 0, -1, 1]
n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
visit = [[0] * m for _ in range(n)]

cnt = 0
max_area = 0


def bfs(i, j):
    area = 0
    q.append((i, j))
    visit[i][j] = 1
    while q:
        y, x = q.popleft()
        area += 1
        for k in range(4):
            ny, nx = y + dy[k], x + dx[k]
            if 0 <= ny < n and 0 <= nx < m and not visit[ny][nx] and board[ny][nx]:
                q.append((ny, nx))
                visit[ny][nx] = 1

    return area


for i in range(n):
    for j in range(m):
        if not visit[i][j] and board[i][j]:
            cnt += 1
            max_area = max(max_area, bfs(i, j))

print(cnt)
print(max_area)
