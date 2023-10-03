n = int(input())
arr = [int(input()) for _ in range(n)]
if n == 1:
    print(arr[0])
    exit()

dp = [[0, 0] for _ in range(n)]  # dp[i][0] = i번째 안마신 경우에서 최대, dp[i][1] = i번째 마신 경우에서 최대
dp[0] = [0, arr[0]]
dp[1] = [arr[0], arr[0] + arr[1]]

for i in range(2, n):
    # i번째 안마심 (1,2)
    dp[i][0] = max(dp[i - 1])

    # i번째 마심 (1,3 / 2,3)
    dp[i][1] = max(dp[i - 2][1] + arr[i], dp[i - 2][0] + arr[i - 1] + arr[i])
print(max(dp[n - 1]))
