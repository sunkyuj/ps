n = int(input())
MAX = 100001
dp = [MAX] * (100001)
dp[2], dp[4], dp[5] = 1, 2, 1
for i in range(6, n + 1):
    dp[i] = min(dp[i - 5] + 1, dp[i - 2] + 1)

if dp[n] == MAX:
    print(-1)
else:
    print(dp[n])
