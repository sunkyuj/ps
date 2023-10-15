n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
dydx = [[0, -1], [-1, 0], [-1, -1]]
dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
for y in range(n):
    for x in range(m):
        for dy, dx in dydx:
            py, px = y + dy, x + dx
            dp[y][x] = max(dp[y][x], dp[py][px] + board[y][x])
print(dp[n - 1][m - 1])
