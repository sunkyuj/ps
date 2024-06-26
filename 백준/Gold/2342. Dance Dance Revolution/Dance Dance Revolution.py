import sys

sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()

MAX = 400000


def get_add(lr, k):
    if k == 0:
        if lr == 0:
            return 0
        else:
            return 2
    elif k == lr:
        return 1
    elif abs(k - lr) == 1 or abs(k - lr) == 3:
        return 3
    else:
        return 4


move = list(map(int, input().split()))
move.pop()
n = len(move)
if n == 0:
    print(0)
    exit()

dp = [[[MAX + 1 for _ in range(5)] for _ in range(5)] for _ in range(n + 1)]
dp[-1][0][0] = 0

for i in range(n):
    # l = move[i]
    for r in range(5):
        for k in range(5):
            add = get_add(move[i], k)
            dp[i][move[i]][r] = min(dp[i][move[i]][r], dp[i - 1][k][r] + add)

    # r = move[i]
    for l in range(5):
        for k in range(5):
            add = get_add(move[i], k)
            dp[i][l][move[i]] = min(dp[i][l][move[i]], dp[i - 1][l][k] + add)

m = MAX + 1
for l in range(5):
    for r in range(5):
        m = min(m, dp[n - 1][l][r])
print(m)
