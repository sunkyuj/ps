n = int(input())  # 10만
arr = list(map(int, input().split()))
all_neg = True
for x in arr:
    if x >= 0:
        all_neg = False
        break
if all_neg:
    print(max(arr))
    exit()

dp = [0] * n
dp1 = [0] * n  # dp1[i]
for i in range(n):
    dp[i] = max(dp[i - 1] + arr[i], 0)

    if arr[i] >= 0:
        dp1[i] = dp1[i - 1] + arr[i]
    else:  # arr[i]가 음수면 i번 패스
        dp1[i] = max(dp[i - 1], dp1[i - 1] + arr[i])

print(max(max(dp), max(dp1)))