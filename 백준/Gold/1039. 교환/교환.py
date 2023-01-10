import sys
from itertools import combinations


sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()

N, K = map(int, input().split())
strn = str(N)
ij = tuple(combinations(range(len(strn)), 2))

dp = [set() for _ in range(K + 1)]
# k = 1
for i, j in ij:
    if not (i == 0 and strn[j] == "0"):
        dp[1].add(strn[:i] + strn[j] + strn[i + 1 : j] + strn[i] + strn[j + 1 :])

for k in range(2, K + 1):  # 10
    for s in dp[k - 1]:  # ?
        for i, j in ij:  # 21
            if not(i == 0 and s[j] == "0"):
                dp[k].add(s[:i] + s[j] + s[i + 1 : j] + s[i] + s[j + 1 :])

ans = max(dp[K]) if dp[K] else -1
print(ans)
