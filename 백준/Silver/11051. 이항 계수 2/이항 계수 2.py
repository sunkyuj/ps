n, k = map(int, input().split())
MOD = 10007
c = [[0 for _ in range(i + 1)] for i in range(n + 1)]

for i in range(1, n + 1):
    c[i][0], c[i][-1] = 1, 1
for i in range(2, n + 1):
    for j in range(1, i):
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD
print(c[n][k])