from collections import deque

n, m = map(int, input().split())
board = [input() for _ in range(n)]
visit = [[0 for _ in range(m)] for _ in range(n)]


def bfs(i, j):
    q = deque()
    q.append((i, j))
    visit[i][j] = 1
    cnt = 0

    while q:
        y, x = q.popleft()
        if board[y][x] == "P":
            cnt += 1
        for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            ny = y + dy
            nx = x + dx
            if 0 <= ny < n and 0 <= nx < m and not visit[ny][nx] and board[ny][nx] != "X":
                q.append((ny, nx))
                visit[ny][nx] = 1
    return cnt


for i in range(n):
    for j in range(m):
        if board[i][j] == "I":
            ans = bfs(i, j)
            if ans:
                print(ans)
            else:
                print("TT")
            break
