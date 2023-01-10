import sys

sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m

MOD = 10007
n = int(input())
# 0 으로 시작 가능

dp = [[0 for _ in range(10)] for _ in range(n + 1)]
for i in range(10):
    dp[1][i] = 1
for l in range(2, n + 1):
    for i in range(10):
        dp[l][i] = sum(dp[l - 1][i:])
        dp[l][i] %= MOD
print(sum(dp[n]) % MOD)
