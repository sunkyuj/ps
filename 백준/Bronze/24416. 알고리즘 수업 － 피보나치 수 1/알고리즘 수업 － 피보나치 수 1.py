n = int(input())
cnt = 0


def fib_dp(n):
    global cnt
    dp = [0] * (n + 1)
    dp[1], dp[2] = 1, 1
    for i in range(3, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]  # code 2
        cnt += 1
    return dp[n]


print(fib_dp(n), cnt)
