import queue

dy = [1, 0, -1, 0, 1, 1, -1, -1]
dx = [0, 1, 0, -1, 1, -1, 1, -1]


def bfs(i, j):
    global w, h
    q = queue.Queue()
    visit[i][j] = 1
    q.put((i, j))
    while not q.empty():
        y, x = q.get()

        for k in range(8):
            ny, nx = y + dy[k], x + dx[k]
            if 0 <= ny < h and 0 <= nx < w and not visit[ny][nx] and board[ny][nx]:
                q.put((ny, nx))
                visit[ny][nx] = 1


while 1:
    w, h = map(int, input().split())
    if (w, h) == (0, 0):
        break

    board = [list(map(int, input().split())) for _ in range(h)]
    ans = 0
    visit = [[0 for _ in range(w)] for _ in range(h)]

    for i in range(h):
        for j in range(w):
            if not visit[i][j] and board[i][j]:
                bfs(i, j)
                ans += 1
    print(ans)
