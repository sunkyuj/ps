n = int(input())
arr = [0] + [int(input()) for _ in range(n)]
dp = [1] * (n + 1)

# 가장 긴 증가하는 수열 찾기
for i in range(1, n + 1):
    for j in range(1, i):
        if arr[j] < arr[i]:
            dp[i] = max(dp[i], dp[j] + 1)

# n- 긴 증가하는 부분수열의 길이
print(n - max(dp))
