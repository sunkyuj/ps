from collections import deque
import sys

DAY = 1
NIGHT = 0
input = lambda: sys.stdin.readline().rstrip()
n, m, k = map(int, input().split())
board = [list(map(int, input())) for _ in range(n)]

dydx = [(1, 0), (0, 1), (-1, 0), (0, -1)]
in_range = lambda y, x: 0 <= y < n and 0 <= x < m
visit = [[[0 for _ in range(k + 1)] for _ in range(m)] for _ in range(n)]


q = deque()
q.append((0, 0, 1, 0, DAY))  # y,x,l,bs,day
visit[0][0][0] = 1
if (0, 0) == (n - 1, m - 1):
    print(1)
    exit()

while q:
    y, x, l, bs, day = q.popleft()
    for dy, dx in dydx:
        ny, nx = y + dy, x + dx
        if (ny, nx) == (n - 1, m - 1):
            print(l + 1)
            exit()
        if not in_range(ny, nx) or visit[ny][nx][bs]:
            continue

        if board[ny][nx] == 0:  # 빈 칸인 경우
            q.append((ny, nx, l + 1, bs, (day + 1) % 2))
            visit[ny][nx][bs] = 1

        else:  # 벽인 경우
            if bs >= k or visit[ny][nx][bs + 1]:  # 벽 더 못부수거나, 이미 방문
                continue

            if day:  # 벽 부수는 경우 (낮)
                q.append((ny, nx, l + 1, bs + 1, NIGHT))
                visit[ny][nx][bs + 1] = 1

            else:  # 머무르는 경우 (밤)
                q.append((y, x, l + 1, bs, DAY))
print(-1)
