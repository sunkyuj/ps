import sys

input = lambda: sys.stdin.readline().rstrip()
MAX = 9999999
n = int(input())  # 2222
board = [list(map(int, input().split())) for _ in range(n)]
dp = [[MAX] * n for _ in range(n)]
dp[0][0] = 0

for i in range(n):
    for j in range(n):
        dcost, rcost = 0, 0
        if i < n - 1:
            if board[i][j] <= board[i + 1][j]:
                dcost = board[i + 1][j] - board[i][j] + 1
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dcost)

        if j < n - 1:
            if board[i][j] <= board[i][j + 1]:
                rcost = board[i][j + 1] - board[i][j] + 1
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + rcost)

print(dp[n - 1][n - 1])
