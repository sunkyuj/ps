from collections import deque

m, n = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
make_wall = lambda bit: [(bit >> i) % 2 for i in range(4)]
walls = [[make_wall(board[i][j]) for j in range(m)] for i in range(n)]
visit = [[0 for _ in range(m)] for _ in range(n)]

dydx = [(0, -1), (-1, 0), (0, 1), (1, 0)]
in_range = lambda y, x: 0 <= y < n and 0 <= x < m

r = [[(i, j) for j in range(m)] for i in range(n)]
areas = {}


def bfs(i, j):
    root = (i, j)
    q = deque()
    q.append((i, j))
    visit[i][j] = 1
    area = 0
    while q:
        y, x = q.popleft()
        r[y][x] = root
        area += 1

        for dir in range(4):
            if walls[y][x][dir]:
                continue
            dy, dx = dydx[dir]
            ny, nx = y + dy, x + dx
            if in_range(ny, nx) and not visit[ny][nx]:
                q.append((ny, nx))
                visit[ny][nx] = 1

    return area


room_cnt, max_area, max_comb_area = 0, 0, 0
for i in range(n):
    for j in range(m):
        if not visit[i][j]:
            areas[(i, j)] = bfs(i, j)
            max_area = max(max_area, areas[(i, j)])
            room_cnt += 1

for i in range(n):
    for j in range(m):
        for dy, dx in dydx:
            ny, nx = i + dy, j + dx
            if in_range(ny, nx) and r[i][j] != r[ny][nx]:
                rt1, rt2 = r[i][j], r[ny][nx]
                max_comb_area = max(max_comb_area, areas[rt1] + areas[rt2])

print(room_cnt)
print(max_area)
print(max_comb_area)
