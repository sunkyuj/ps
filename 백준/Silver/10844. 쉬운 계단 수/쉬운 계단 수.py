import sys

sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()
MOD = 1000000000

n = int(input())
# dp[l][k] = 길이 l짜리 k으로 끝나는 계단수의 개수
dp = [[0 for _ in range(10)] for _ in range(n + 1)]

for k in range(1, 10):
    dp[1][k] = 1

for l in range(2, n + 1):
    for k in range(10):
        if k > 0:  # 1~9
            dp[l][k] += dp[l - 1][k - 1]
        if k < 9:  # 0~8
            dp[l][k] += dp[l - 1][k + 1]
        dp[l][k] %= MOD
print(sum(dp[n]) % MOD)
