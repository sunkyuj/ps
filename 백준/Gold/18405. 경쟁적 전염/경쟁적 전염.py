from collections import deque

n, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
s, _x, _y = map(int, input().split())

qs = [deque() for _ in range(k + 1)]
visit = [[0 for _ in range(n)] for _ in range(n)]  # 40000

in_range = lambda y, x: 0 <= y < n and 0 <= x < n


def bfs(i, j):
    edges = set()
    vnum = board[i][j]
    q = deque()
    q.append((i, j))
    visit[i][j] = 1

    while q:
        y, x = q.popleft()
        is_edge = False

        for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            ny, nx = y + dy, x + dx
            if not in_range(ny, nx):
                continue
            if board[ny][nx] == vnum and not visit[ny][nx]:
                visit[ny][nx] = 1
                q.append((ny, nx))
            if board[ny][nx] == 0:
                is_edge = True

        if is_edge:
            edges.add((y, x))

    return edges


for i in range(n):  # 40000
    for j in range(n):
        if board[i][j]:
            vnum = board[i][j]
            qs[vnum].extend(bfs(i, j))

for _ in range(s):  # 10000
    for i in range(1, k + 1):  # 1000
        new_edges = set()
        vnum = 0
        while qs[i]:
            y, x = qs[i].popleft()
            vnum = board[y][x]
            for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                ny, nx = y + dy, x + dx
                if not in_range(ny, nx):
                    continue
                if board[ny][nx] == 0:
                    board[ny][nx] = vnum
                    new_edges.add((ny, nx))
        qs[i].extend(new_edges)

print(board[_x - 1][_y - 1])
