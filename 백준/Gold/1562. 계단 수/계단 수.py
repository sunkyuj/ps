MOD = 1000000000
n = int(input())

# s = 0
# for n in range(1, 41):

dp = [[[0 for k in range(10)] for bit in range(1024)] for l in range(n + 1)]
# dp[l][bit][k] = 길이가 l이고 bit의 숫자들을 포함한, k로 끝나는 계단수의 개수

case = {(10, 1023, 0), (10, 1022, 1), (10, 511, 8)}
for k in range(1, 10):
    dp[1][1 << k][k] = 1

for l in range(1, n):
    for bit in range(1024):
        for k in range(10):
            if k != 0:
                mask = 1 << (k - 1)
                dp[l + 1][bit | mask][k - 1] += dp[l][bit][k]
                dp[l + 1][bit | mask][k - 1] %= MOD
            if k != 9:
                mask = 1 << (k + 1)
                dp[l + 1][bit | mask][k + 1] += dp[l][bit][k]
                dp[l + 1][bit | mask][k + 1] %= MOD

print(sum(dp[n][1023]) % MOD)
# s += (sum(dp[n][1023]) % MOD)

# print(s)
