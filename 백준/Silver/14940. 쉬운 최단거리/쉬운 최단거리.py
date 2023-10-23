from collections import deque

n, m = map(int, input().split())
in_range = lambda y, x: 0 <= y < n and 0 <= x < m

board = [list(map(int, input().split())) for _ in range(n)]
visit = [[0 for _ in range(m)] for _ in range(n)]
ans = [[-1 for _ in range(m)] for _ in range(n)]

q = deque()
for i in range(n):
    for j in range(m):
        if board[i][j] == 2:
            q.append((i, j, 0))
            visit[i][j] = 1
        if board[i][j] == 0:
            ans[i][j] = 0
while q:
    y, x, l = q.popleft()
    ans[y][x] = l

    for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
        ny, nx = y + dy, x + dx
        if in_range(ny, nx) and not visit[ny][nx] and board[ny][nx]:
            q.append((ny, nx, l + 1))
            visit[ny][nx] = 1


for i in range(n):
    for j in range(m):
        print(ans[i][j], end=" ")
    print()
