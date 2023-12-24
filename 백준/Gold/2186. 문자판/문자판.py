n, m, k = map(int, input().split())
board = [list(input()) for _ in range(n)]
word = input()
ans = 0

dydx = [(1, 0), (0, 1), (-1, 0), (0, -1)]
in_range = lambda y, x: 0 <= y < n and 0 <= x < m
memo = [[[-1] * len(word) for _ in range(m)] for _ in range(n)]
# memo[y][x][idx]


def dfs(y, x, idx):
    if idx == len(word) - 1:
        memo[y][x][idx] = 1
        return 1
    if memo[y][x][idx] != -1:
        return memo[y][x][idx]

    memo[y][x][idx] = 0
    for dy, dx in dydx:
        ny, nx = y, x
        for _ in range(k):
            ny, nx = ny + dy, nx + dx
            if not in_range(ny, nx):
                break
            if board[ny][nx] == word[idx + 1]:
                memo[y][x][idx] += dfs(ny, nx, idx + 1)
    return memo[y][x][idx]


for i in range(n):
    for j in range(m):
        if word[0] == board[i][j]:
            memo[i][j][0] = dfs(i, j, 0)
            ans += memo[i][j][0]

print(ans)
