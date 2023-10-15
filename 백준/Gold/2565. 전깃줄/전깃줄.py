n = int(input())  # 100
lines = [list(map(int, input().split())) for _ in range(n)]
lines.sort()

dp = [1] * n  # i번까지의 LIS
for i in range(1, n):
    for j in range(i):
        if lines[j][1] < lines[i][1]:
            dp[i] = max(dp[i], dp[j] + 1)
print(n - max(dp))