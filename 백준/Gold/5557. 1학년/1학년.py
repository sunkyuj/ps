n = int(input())
arr = list(map(int, input().split()))
dp = [[0 for _ in range(21)] for _ in range(n - 1)]
# dp[i][res] = i번째에서 결과가 res인 것의 개수
dp[0][arr[0]] = 1

for i in range(1, n - 1):
    for result in range(21):
        prev_cnt = dp[i - 1][result]
        if result + arr[i] <= 20:
            dp[i][result + arr[i]] += prev_cnt
        if result - arr[i] >= 0:
            dp[i][result - arr[i]] += prev_cnt

print(dp[-1][arr[-1]])
