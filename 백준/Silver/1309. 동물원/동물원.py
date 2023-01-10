import sys

sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()
MOD = 9901

n = int(input())
"""
n   1   2   3   4   5   6   7   8   9
    3

"""
# dp[i][3] = i번째 줄에서 0,1,2 가능한 경우의 개수
# sum(dp[i]) == 가능한 경우의 수
dp = [[0, 0, 0] for _ in range(n)]  # 0 = no, 1 = right, 2 = left
dp[0] = [1, 1, 1]

for i in range(1, n):
    # 0 no
    dp[i][0] = (sum(dp[i - 1])) % MOD
    # 1 right
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD
    # 2 left
    dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD
print(sum(dp[n - 1]) % MOD)
