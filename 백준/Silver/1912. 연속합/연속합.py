MIN = -1000 * 100000 - 1
n = int(input())
a = list(map(int, input().split()))


dp = [0 for _ in range(n)]
dp[0] = a[0]
ans = dp[0]

for i in range(1, n):
    dp[i] = max(dp[i - 1] + a[i], a[i])
    ans = max(ans, dp[i])
print(ans)
