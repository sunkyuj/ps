from collections import deque

m, n, k = map(int, input().split())  # 세로, 가로, 자르는수
board = [[1] * n for _ in range(m)]
visit = [[0] * n for _ in range(m)]
dy, dx = [1, -1, 0, 0], [0, 0, 1, -1]
q = deque()


for _ in range(k):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(y1, y2):
        for j in range(x1, x2):
            board[i][j] = 0


def bfs(i, j):
    q.append((i, j))
    visit[i][j] = 1

    area = 0
    while q:
        y, x = q.popleft()
        area += 1
        for k in range(4):
            ny, nx = y + dy[k], x + dx[k]
            if 0 <= ny < m and 0 <= nx < n and not visit[ny][nx] and board[ny][nx]:
                q.append((ny, nx))
                visit[ny][nx] = 1
    return area


cnt = 0
areas = []
for i in range(m):
    for j in range(n):
        if not visit[i][j] and board[i][j]:
            cnt += 1
            areas.append(bfs(i, j))
print(cnt)
areas.sort()
for a in areas:
    print(a, end=" ")
