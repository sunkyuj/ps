import sys

sys.setrecursionlimit(10**7)
n = int(input())
board = [input() for _ in range(n)]
color = [[-1 for _ in range(n)] for _ in range(n)]
dydx = [(1, 0), (0, 1), (-1, 0), (0, -1), (1, -1), (-1, 1)]
in_range = lambda y, x: 0 <= y < n and 0 <= x < n

ans = 0


def dfs(y, x, c):
    global ans
    ans = max(ans, 1)

    color[y][x] = c

    for dy, dx in dydx:
        ny, nx = y + dy, x + dx
        if not in_range(ny, nx) or board[ny][nx] != "X":
            continue

        # 0 1 0 1 번갈아서 색칠
        if color[ny][nx] == -1:  # no color
            ans = max(ans, 2)
            dfs(ny, nx, 1 - c)
        if color[ny][nx] == c:
            print(3)
            exit()


for i in range(n):
    for j in range(n):
        if board[i][j] == "X" and color[i][j] == -1:
            # bfs(i, j)
            dfs(i, j, 0)

print(ans)
