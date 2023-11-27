from collections import deque

n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]

visit = [[0 for _ in range(m)] for _ in range(n)]


def bfs(i, j):
    c = board[i][j]
    q = deque()  # py,px,y,x
    q.append((-1, -1, i, j))
    visit[i][j] = 1
    while q:
        py, px, y, x = q.popleft()

        for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            ny, nx = y + dy, x + dx
            if not (0 <= ny < n and 0 <= nx < m and board[ny][nx] == c):
                continue
            if visit[ny][nx] and (ny, nx) != (py, px):
                return 1
            if not visit[ny][nx]:
                q.append((y, x, ny, nx))
                visit[ny][nx] = 1

    return 0


for i in range(n):
    for j in range(m):
        if not visit[i][j]:
            if bfs(i, j):
                print("Yes")
                exit()
print("No")
