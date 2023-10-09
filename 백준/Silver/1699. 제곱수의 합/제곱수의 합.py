import bisect

MAX = 99999999
n = int(input())
"""
1 = 1^
2 = 1^ + 1^
3 = 1^ + 1^ + 1^
4 = 2^
5 = 2^ + 1^
6 = 2^ + 1^ + 1^
7 = 2^ + 1^ + 1^ + 1^
8 = 2^ + 2^
"""

sq = [i * i for i in range(330)]
dp = [MAX for _ in range(n + 1)]
i = 1
while i * i <= n:
    dp[i * i] = 1
    i += 1


def f(num):
    if dp[num] != MAX:
        return dp[num]

    sqrt_num = bisect.bisect_right(sq, num) - 1

    for i in range(sqrt_num, 0, -1):
        x = f(num - sq[i]) + f(sq[i])
        dp[num] = min(dp[num], x)

    return dp[num]


print(f(n))
