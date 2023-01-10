import sys

sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
p = [0] + list(map(int, input().split()))

# dp[i][k] = i번 팩까지만 이용해서 k개의 카드 사는 최댓값
dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]


for k in range(1, n + 1):  # 1번 팩만 사용
    dp[1][k] = k * p[1]

for i in range(2, n + 1):
    for k in range(1, n + 1):
        dp[i][k] = dp[i - 1][k]  # 이번 팩 구매 x
        if k >= i:
            dp[i][k] = max(dp[i][k], dp[i][k - i] + p[i])  # 이번 팩 구매 o
print(dp[n][n])
