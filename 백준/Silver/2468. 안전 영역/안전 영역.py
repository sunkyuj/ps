import queue

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]


def bfs(i, j):
    global n
    q = queue.Queue()
    q.put((i, j))
    while not q.empty():
        y, x = q.get()
        for k in range(4):
            ny, nx = y + dy[k], x + dx[k]
            if 0 <= ny < n and 0 <= nx < n and not visit[ny][nx] and board[ny][nx] > 0:
                q.put((ny, nx))
                visit[ny][nx] = 1
    return 1


n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
highest = 0
for r in board:
    highest = max(highest, max(r))

ans = 1
for rain in range(1, highest):
    visit = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            board[i][j] -= 1

    cnt = 0
    for i in range(n):
        for j in range(n):
            if not visit[i][j] and board[i][j] > 0:
                visit[i][j] = 1
                cnt += bfs(i, j)
    ans = max(ans, cnt)

print(ans)
