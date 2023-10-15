n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
dp = [[0 for _ in range(n)] for _ in range(n)]
dp[0][0] = 1

for i in range(n):
    for j in range(n):
        if (i, j) == (n - 1, n - 1):
            break
        jump = board[i][j]
        # right
        if j + jump < n:
            dp[i][j + jump] += dp[i][j]
            # down
        if i + jump < n:
            dp[i + jump][j] += dp[i][j]


print(dp[-1][-1])
