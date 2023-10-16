n, m = map(int, input().split())
board = [list(map(int, input())) for _ in range(n)]
ans = 0
dp = [[0] * m for _ in range(n)]

for i in range(n):
    for j in range(m):
        dp[i][j] = board[i][j]
        ans = max(ans, dp[i][j])

for i in range(1, n):
    for j in range(1, m):
        if dp[i][j] and dp[i - 1][j] and dp[i][j - 1] and dp[i - 1][j - 1]:
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
        ans = max(ans, dp[i][j])

print(ans * ans)
