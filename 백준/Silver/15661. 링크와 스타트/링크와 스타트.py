from itertools import combinations

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
all = list(range(n))
ans = 9999


def power(team):
    s = 0
    for i in team:
        for j in team:
            s += board[i][j]
    return s


for r in range(1, n // 2 + 1):  # 10
    for t1 in combinations(range(n), r):
        t2 = set(all) - set(t1)
        ans = min(ans, abs(power(t1) - power(t2)))

print(ans)
