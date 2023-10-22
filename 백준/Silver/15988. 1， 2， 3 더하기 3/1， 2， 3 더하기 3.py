MOD = 1000000009
dp = [0] * 1000001
dp[1], dp[2], dp[3] = 1, 2, 4

for i in range(4, 1000001):
    dp[i] = (dp[i] + dp[i - 1]) % MOD
    dp[i] = (dp[i] + dp[i - 2]) % MOD
    dp[i] = (dp[i] + dp[i - 3]) % MOD

for _ in range(int(input())):
    print(dp[int(input())])
