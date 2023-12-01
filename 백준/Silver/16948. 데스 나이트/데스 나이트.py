from collections import deque

n = int(input())
dydx = [(-2, -1), (-2, 1), (0, -2), (0, 2), (2, -1), (2, 1)]
in_range = lambda y, x: 0 <= y < n and 0 <= x < n

r1, c1, r2, c2 = map(int, input().split())

q = deque()
visit = [[0] * n for _ in range(n)]

q.append((r1, c1, 0))
visit[r1][c1] = 1
while q:
    y, x, cnt = q.popleft()
    if (y, x) == (r2, c2):
        print(cnt)
        exit()
    for dy, dx in dydx:
        ny, nx = y + dy, x + dx
        if in_range(ny, nx) and not visit[ny][nx]:
            q.append((ny, nx, cnt + 1))
            visit[ny][nx] = 1
print(-1)
