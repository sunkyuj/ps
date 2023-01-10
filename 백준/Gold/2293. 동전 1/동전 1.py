import sys

# sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m


n, k = map(int, input().split())
coin = [int(input()) for _ in range(n)]
coin.sort()

# dp[i][k] = i번 동전까지만 써서 k원 만드는 방법 수
dp = [0 for _ in range(k + 1)]
dp[0] = 1

for money in range(1, k + 1):  # coin[0]만 사용
    if money % coin[0] == 0:
        dp[money] = 1

for i in range(1, n):
    for money in range(k + 1):
        if money >= coin[i]:
            dp[money] += dp[money - coin[i]]


"""
# 메모리 초과!!!!
for i in range(1, n):
    for money in range(k + 1):
        if money >= coin[i]:
            dp[i][money] += dp[i][money - coin[i]]  # coin[i] 사용o
        dp[i][money] += dp[i - 1][money]  # coin[i] 사용x
"""

print(dp[k])
