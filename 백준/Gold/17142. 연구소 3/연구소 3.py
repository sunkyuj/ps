from collections import deque
from itertools import combinations

MAX = 999999999

n, m = map(int, input().split())
dydx = [(1, 0), (0, 1), (-1, 0), (0, -1)]
in_range = lambda y, x: 0 <= y < n and 0 <= x < n
board = [list(map(int, input().split())) for _ in range(n)]

vir_able = []
spaces = 0
for i in range(n):
    for j in range(n):
        if board[i][j] == 2:
            vir_able.append((i, j))
        if board[i][j] == 0:
            spaces += 1
if spaces == 0:
    print(0)
    exit()


def bfs(vir_list):
    q = deque()
    visit = [[0] * n for _ in range(n)]
    for i, j in vir_list:
        visit[i][j] = 1
        q.append((i, j, 0))
    cnt = 0
    while q:
        y, x, time = q.popleft()
        if board[y][x] == 0:
            cnt += 1

        if cnt == spaces:
            return time

        for dy, dx in dydx:
            ny, nx = y + dy, x + dx
            if not in_range(ny, nx) or visit[ny][nx]:
                continue
            if board[ny][nx] != 1:
                q.append((ny, nx, time + 1))
                visit[ny][nx] = 1

    return MAX


ans = MAX
for comb in combinations(vir_able, m):
    ans = min(ans, bfs(list(comb)))
if ans == MAX:
    print(-1)
else:
    print(ans)
