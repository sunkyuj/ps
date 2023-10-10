n = int(input())
dp = [[0 for _ in range(8)] for _ in range(n)]
# dp[n][i] = 가로길이 n일때, i번 모양으로 채우는 경우의 수

dp[0][0] = 1
dp[0][3] = 1
dp[0][6] = 1

for i in range(1, n):
    # i-1은 꽉 차야됨
    dp[i][0] = dp[i - 1][7]  # 무조건 전 칸이 꽉 차야함

    dp[i][1] = dp[i - 1][6]
    dp[i][3] = dp[i - 1][4] + dp[i - 1][7]  # 2칸
    dp[i][4] = dp[i - 1][3]
    dp[i][6] = dp[i - 1][1] + dp[i - 1][7]  # 2칸

    dp[i][7] = dp[i - 1][0] + dp[i][1] + dp[i][4]


print(dp[n - 1][7])