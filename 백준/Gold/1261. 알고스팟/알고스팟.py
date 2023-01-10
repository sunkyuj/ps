import sys
from queue import Queue

input = lambda: sys.stdin.readline().rstrip()

dy = [1, 0, -1, 0]
dx = [0, -1, 0, 1]

m, n = map(int, input().split())
in_range = lambda y, x: 0 <= y < n and 0 <= x < m

board = [input() for _ in range(n)]
dp = [[10000 for _ in range(m)] for _ in range(n)]


visit = [[0 for _ in range(m)] for _ in range(n)]

ans = 0
dp[0][0] = 0
q, wall_q = Queue(), Queue()
q.put((0, 0))

while 1:
    while not q.empty():
        y, x = q.get()

        if y == n - 1 and x == m - 1:
            print(ans)
            exit()

        for k in range(4):
            ny, nx = y + dy[k], x + dx[k]
            if not in_range(ny, nx):
                continue
            if visit[ny][nx]:
                continue

            if board[ny][nx] == "0":
                q.put((ny, nx))
            else:
                wall_q.put((ny, nx))
            visit[ny][nx] = 1

    while not wall_q.empty():
        y, x = wall_q.get()
        q.put((y, x))
    ans += 1