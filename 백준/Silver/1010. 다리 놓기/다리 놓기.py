memo = [[0 for _ in range(i + 1)] for i in range(30)]
"""
0
1 1
1 2 1
1 3 3 1
1 4 6 4 1
"""
for i in range(1, 30):
    memo[i][0] = memo[i][i] = 1

for i in range(2, 30):
    for j in range(1, i):
        memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j]


for _ in range(int(input())):
    n, m = map(int, input().split())
    print(memo[m][n])
