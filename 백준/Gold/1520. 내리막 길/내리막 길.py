import sys

sys.setrecursionlimit(10**8)

m, n = map(int, input().split())  # 500 500 -> 250,000
board = [list(map(int, input().split())) for _ in range(m)]  # 각 10000 이하
dy, dx = [1, 0, -1, 0], [0, 1, 0, -1]
memo = [[-1] * n for _ in range(m)]
memo[-1][-1] = 1

# m, n = 500, 500
# board = [[1000 - i - j for j in range(500)] for i in range(500)]
# memo = [[0] * 500 for _ in range(500)]
# memo[-1][-1] = 1


def dfs(y, x):

    if memo[y][x] != -1:
        return memo[y][x]

    memo[y][x] = 0
    for k in range(4):
        ny, nx = y + dy[k], x + dx[k]
        if not (0 <= ny < m and 0 <= nx < n):
            continue

        if board[ny][nx] < board[y][x]:
            memo[y][x] += dfs(ny, nx)

    return memo[y][x]


print(dfs(0, 0))
