import sys
from itertools import permutations
from collections import deque

input = lambda: sys.stdin.readline().rstrip()
in_range = lambda y, x: 0 <= y < h and 0 <= x < w
dydx = [(1, 0), (0, 1), (-1, 0), (0, -1)]
MAX = 401


def bfs(a, b):
    q = deque()
    visit = [[0 for _ in range(w)] for _ in range(h)]
    q.append((targets[a][0], targets[a][1], 0))
    visit[targets[a][0]][targets[a][1]] = 1

    while q:
        y, x, cnt = q.popleft()
        if (y, x) == targets[b]:
            dist[a][b] = cnt
            dist[b][a] = cnt
            return
        for dy, dx in dydx:
            ny, nx = y + dy, x + dx
            if in_range(ny, nx) and board[ny][nx] != "x" and not visit[ny][nx]:
                q.append((ny, nx, cnt + 1))
                visit[ny][nx] = 1
    return


def get_len(order):
    l = dist[0][order[0]]
    for i in range(len(order) - 1):
        a = order[i]
        b = order[i + 1]
        d = dist[a][b]
        if d == MAX:
            return -1
        l += d
    return l


while 1:
    w, h = map(int, input().split())
    if (w, h) == (0, 0):
        break
    board = [list(input()) for _ in range(h)]
    targets = []
    sy, sx = -1, -1
    for i in range(h):
        for j in range(w):
            if board[i][j] == "*":
                targets.append((i, j))
            if board[i][j] == "o":
                sy, sx = i, j
    targets.insert(0, (sy, sx))

    # 각 타겟에서 각 타겟으로의 최단경로
    dist = [[MAX for _ in range(len(targets))] for _ in range(len(targets))]
    for a in range(len(targets) - 1):
        for b in range(a + 1, len(targets)):
            bfs(a, b)
    ans = MAX
    # 방문 순서
    for order in permutations(range(1, len(targets))):
        l = get_len(order)
        if l == -1:
            break

        ans = min(ans, l)

    if ans != MAX:
        print(ans)
    else:
        print(-1)
