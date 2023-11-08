n = int(input())  # 1000
dp = [i for i in range(2 * n + 1)]

for i in range(2, n + 1):
    cnt = dp[i] + 1  # copy
    for j in range(i * 2, 2 * n + 1, i):
        cnt += 1  # paste
        dp[j] = min(dp[j], cnt)

        for k in range(j - 1, 1, -1):
            diff = j - k
            dp[k] = min(dp[k], dp[j] + diff)
print(dp[n])
