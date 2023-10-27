n = int(input())
p = list(map(int, input().split()))
MAX = 99999999
dp = [MAX] * (n + 1)
dp[0] = 0

for i in range(1, n + 1):
    for j in range(1, i + 1):
        dp[i] = min(dp[i], dp[i - j] + p[j - 1])

print(dp[-1])
