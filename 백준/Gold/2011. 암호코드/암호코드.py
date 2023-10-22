MOD = 1000000
s = input()
if s[0] == "0":
    print(0)
    exit()

l = len(s)
to_alp = lambda x: chr(int(x) + 64)
in_range = lambda x: 1 <= int(x) <= 26
dp = [[0, 0] for _ in range(5001)]  # dp[i][0] = i번째 놈으로 해석, dp[i][1] = i-1,i번째 놈으로 해석
dp[0] = [1, 0]
if l >= 2:
    dp[1][0] = 1 if s[1] != "0" else 0
    dp[1][1] = 1 if in_range(s[:2]) else 0

for i in range(2, l):
    two = s[i - 1 : i + 1]
    if two in ("00", "30", "40", "50", "60", "70", "80", "90"):
        print(0)
        exit()

    if s[i] != "0":
        dp[i][0] = (dp[i - 1][0] % MOD + dp[i - 1][1] % MOD) % MOD

    if s[i - 1] != "0" and in_range(two):
        dp[i][1] = (dp[i - 2][0] % MOD + dp[i - 2][1] % MOD) % MOD
print(sum(dp[l - 1]) % MOD)
