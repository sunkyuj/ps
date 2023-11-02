n, m, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
visit = [[0 for _ in range(m)] for _ in range(n)]

dydx = [(1, 0), (0, 1), (-1, 0), (0, -1)]
in_range = lambda y, x: 0 <= y < n and 0 <= x < m

ans = -1000001


def check(y, x):
    for dy, dx in dydx:
        ny, nx = y + dy, x + dx
        if not in_range(ny, nx):
            continue
        if visit[ny][nx]:
            return False
    return True


def f(y, x, cnt, s):

    if cnt == k:
        global ans
        ans = max(ans, s)
        return
    if y == n:
        return

    ny, nx = y, x
    nx += 1
    if nx == m:
        nx = 0
        ny += 1

    # 0
    f(ny, nx, cnt, s)

    # 1
    if check(y, x):
        visit[y][x] = 1
        f(ny, nx, cnt + 1, s + board[y][x])
        visit[y][x] = 0

    return


f(0, 0, 0, 0)

print(ans)
