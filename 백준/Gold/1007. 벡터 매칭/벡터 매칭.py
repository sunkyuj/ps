import sys
import math
from itertools import combinations

sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()

T = int(input())
for _ in range(T):
    n = int(input())
    ps = [0 for _ in range(n)]
    xtotal, ytotal = 0, 0
    for i in range(n):
        x, y = map(int, input().split())
        xtotal += x
        ytotal += y
        ps[i] = (x, y)

    min_scala = 1000000
    comb = list(combinations(range(n), n // 2))
    for c in comb[: len(comb) // 2]:  # 조합은 어떨 때 절반만 봐도 됨
        
        xsum, ysum = 0, 0
        for i in c:
            xsum += ps[i][0]
            ysum += ps[i][1]

        xsum -= xtotal - xsum
        ysum -= ytotal - ysum

        scala = math.sqrt(xsum ** 2 + ysum ** 2)
        if min_scala > scala:
            min_scala = scala

    print(min_scala)