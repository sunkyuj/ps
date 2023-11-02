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

    for i in range(y, n):
        for j in range(x if i == y else 0, m):

            if not visit[i][j] and check(i, j):
                visit[i][j] = 1
                f(i, j, cnt + 1, s + board[i][j])
                visit[i][j] = 0

f(0, 0, 0, 0)
print(ans)
