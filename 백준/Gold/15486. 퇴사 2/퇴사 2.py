import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
t, p = [0 for _ in range(n + 1)], [0 for _ in range(n + 1)]
for i in range(1, n + 1):
    t[i], p[i] = map(int, input().split())

dp = [0 for _ in range(n + 1)]

for i in range(1, n + 1):
    fin_date = i + t[i] - 1  # 당일 포함
    dp[i] = max(dp[i], dp[i - 1])
    if fin_date <= n:
        dp[fin_date] = max(dp[fin_date], dp[i - 1] + p[i])
print(max(dp))
