n = int(input())
arr = list(map(int, input().split()))
dp = [arr[i] for i in range(n)]


for i in range(1, n):
    for j in range(i - 1, -1, -1):
        if arr[i] > arr[j]:
            dp[i] = max(dp[i], dp[j] + arr[i])
print(max(dp))