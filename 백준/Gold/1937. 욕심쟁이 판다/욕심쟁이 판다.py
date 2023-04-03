import sys

sys.setrecursionlimit(10**8)

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]

dy, dx = [1, -1, 0, 0], [0, 0, -1, 1]
memo = [[0] * n for _ in range(n)]


def dfs(y, x):
    if memo[y][x]:
        return memo[y][x]

    for k in range(4):
        ny, nx = y + dy[k], x + dx[k]
        if 0 <= ny < n and 0 <= nx < n and board[ny][nx] > board[y][x]:
            memo[y][x] = max(memo[y][x], dfs(ny, nx))

    memo[y][x] += 1  # 본인 포함
    return memo[y][x]


for i in range(n):
    for j in range(n):
        dfs(i, j)

ans = 0
for r in memo:
    ans = max(ans, max(r))

print(ans)
