import sys

sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()

MOD = 1000000000

N, K = map(int, input().split())


dp = [[0 for _ in range(N + 1)] for _ in range(K + 1)]

for n in range(N + 1):  # k=1, 하나만 써서 n 만들기 -> 무조건 1
    dp[1][n] = 1
for k in range(2, K + 1):
    for n in range(N + 1):
        dp[k][n] = sum(dp[k - 1][: n + 1])
        dp[k][n] %= MOD
print(dp[K][N])