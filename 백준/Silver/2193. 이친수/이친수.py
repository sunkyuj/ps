n = int(input())
memo = [[0, 0] for _ in range(91)]
memo[1][1] = 1
for i in range(2, n + 1):
    memo[i][0] = memo[i - 1][0] + memo[i - 1][1]  # 0으로 끝남
    memo[i][1] = memo[i - 1][0]  # 1로 끝남
print(sum(memo[n]))