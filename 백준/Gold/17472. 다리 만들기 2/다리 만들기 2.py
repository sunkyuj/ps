from collections import deque

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
visit = [[0 for _ in range(m)] for _ in range(n)]
in_range = lambda y, x: 0 <= y < n and 0 <= x < m
island_num = 0
islands = {}
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]  # urdl


def div(i, j, island_num):
    q = deque()
    q.append((i, j))
    visit[i][j] = 1
    lands = []

    while q:
        y, x = q.popleft()
        board[y][x] = island_num
        dirs = []
        for k in range(4):
            ny, nx = y + dy[k], x + dx[k]
            if not in_range(ny, nx) or visit[ny][nx]:
                continue
            if board[ny][nx] == 1:
                q.append((ny, nx))
                visit[ny][nx] = 1
            else:
                dirs.append(k)
        if dirs:
            lands.append((y, x, dirs))
    return lands


for i in range(n):
    for j in range(m):
        if board[i][j] and not visit[i][j]:
            island_num += 1
            islands[island_num] = div(i, j, island_num)


conn = set()
for i, info in islands.items():
    for y, x, dirs in info:
        for dir in dirs:
            l = 0
            ny, nx = y, x
            while in_range(ny + dy[dir], nx + dx[dir]):
                ny += dy[dir]
                nx += dx[dir]
                if board[ny][nx]:  # 닿았음
                    break
                l += 1

            end = board[ny][nx]
            if l <= 1 or end == i or end == 0:
                continue
            if (l, end, i) not in conn:
                conn.add((l, i, end))

conn = sorted(conn)
# print(conn)

check = set()
ans = 0
cnt = 0

root = [i for i in range(island_num + 1)]


def union(v1, v2):
    r1, r2 = find(v1), find(v2)
    root[r2] = r1


def find(v):
    if root[v] == v:
        return v
    root[v] = find(root[v])
    return root[v]


for l, a, b in conn:
    if (a, b) not in check and find(a) != find(b):
        check.add((a, b))
        ans += l
        cnt += 1
        union(a, b)
    if cnt == island_num - 1:
        r = find(1)
        for i in range(2, island_num + 1):
            if r != find(i):
                print(-1)
                exit()
        print(ans)
        exit()
print(-1)

"""
4 6
0 1 1 0 1 1
1 0 1 0 0 1
1 0 1 1 0 0
1 0 1 1 1 0
"""
