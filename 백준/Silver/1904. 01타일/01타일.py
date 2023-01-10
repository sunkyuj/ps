import sys

sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m

MOD = 15746
n = int(input())
dp = [0 for _ in range(n + 2)]
dp[1], dp[2] = 1, 2

for i in range(3, n + 1):
    dp[i] = dp[i - 2] + dp[i - 1]  # 00 + 1
    dp[i] %= MOD


print(dp[n])
