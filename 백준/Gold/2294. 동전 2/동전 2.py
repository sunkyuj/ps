n, k = map(int, input().split())  # 100, 10000
coins = [int(input()) for _ in range(n)]
MAX = 10001
coins = sorted(list(set(coins)))

dp = [MAX] * (k + 1)
dp[0] = 0  # 0원 만들기는 불가능

for coin in coins:  # 100
    # 동전으로 k원 만들기
    for val in range(coin, k + 1):  # 10000
        dp[val] = min(dp[val], dp[val - coin] + 1)

if dp[k] == MAX:
    print(-1)
else:
    print(dp[k])
