from collections import deque

k = int(input())
w, h = map(int, input().split())
dydx = [(1, 0), (0, 1), (-1, 0), (0, -1)]
h_move = [
    (2, 1),
    (2, -1),
    (-2, 1),
    (-2, -1),
    (1, 2),
    (-1, 2),
    (1, -2),
    (-1, -2),
]
in_range = lambda y, x: 0 <= y < h and 0 <= x < w

board = [list(map(int, input().split())) for _ in range(h)]
visit = [[k + 1] * w for _ in range(h)]
q = deque()
q.append((0, 0, 0, 0))  # y,x,l,hops
visit[0][0] = k

while q:
    y, x, l, hops = q.popleft()
    if (y, x) == (h - 1, w - 1):
        print(l)
        exit()

    # hop
    for dy, dx in h_move:
        ny, nx = y + dy, x + dx
        if not in_range(ny, nx) or board[ny][nx] == 1:
            continue
        if hops < k and hops + 1 < visit[ny][nx]:
            q.append((ny, nx, l + 1, hops + 1))
            visit[ny][nx] = hops + 1

    # move
    for dy, dx in dydx:
        ny, nx = y + dy, x + dx
        if not in_range(ny, nx) or board[ny][nx] == 1:
            continue
        if hops < visit[ny][nx]:
            q.append((ny, nx, l + 1, hops))
            visit[ny][nx] = hops

print(-1)
