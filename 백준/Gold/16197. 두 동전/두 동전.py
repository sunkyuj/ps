n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]
balls = []
ans = 11
in_range = lambda y, x: 0 <= y < n and 0 <= x < m
dydx = [(1, 0), (0, 1), (-1, 0), (0, -1)]
for i in range(n):
    for j in range(m):
        if board[i][j] == "o":
            balls.append((i, j))
            board[i][j] = "."


def f(cnt, b1, b2):
    global ans

    if cnt == 11:
        return

    y1, x1 = b1
    y2, x2 = b2
    for k in range(4):  # drul
        dy, dx = dydx[k]
        ny1, nx1 = y1 + dy, x1 + dx
        ny2, nx2 = y2 + dy, x2 + dx

        is_in = 0
        is_in += in_range(ny1, nx1)
        is_in += in_range(ny2, nx2)
        if is_in == 0:
            continue
        elif is_in == 1:
            ans = min(ans, cnt)
            continue

        if k == 0:  # d
            if y1 > y2:
                # b1 first
                if board[ny1][nx1] == "#":
                    ny1 -= dy
                    nx1 -= dx
                if board[ny2][nx2] == "#" or (ny2, nx2) == (ny1, nx1):
                    ny2 -= dy
                    nx2 -= dx
            else:
                # b2 first
                if board[ny2][nx2] == "#":
                    ny2 -= dy
                    nx2 -= dx
                if board[ny1][nx1] == "#" or (ny2, nx2) == (ny1, nx1):
                    ny1 -= dy
                    nx1 -= dx
        elif k == 1:  # r
            if x1 > x2:
                # b1 first
                if board[ny1][nx1] == "#":
                    ny1 -= dy
                    nx1 -= dx
                if board[ny2][nx2] == "#" or (ny2, nx2) == (ny1, nx1):
                    ny2 -= dy
                    nx2 -= dx
            else:
                # b2 first
                if board[ny2][nx2] == "#":
                    ny2 -= dy
                    nx2 -= dx
                if board[ny1][nx1] == "#" or (ny2, nx2) == (ny1, nx1):
                    ny1 -= dy
                    nx1 -= dx
        elif k == 2:  # u
            if y1 < y2:
                # b1 first
                if board[ny1][nx1] == "#":
                    ny1 -= dy
                    nx1 -= dx
                if board[ny2][nx2] == "#" or (ny2, nx2) == (ny1, nx1):
                    ny2 -= dy
                    nx2 -= dx
            else:
                # b2 first
                if board[ny2][nx2] == "#":
                    ny2 -= dy
                    nx2 -= dx
                if board[ny1][nx1] == "#" or (ny2, nx2) == (ny1, nx1):
                    ny1 -= dy
                    nx1 -= dx
        elif k == 3:  # l
            if x1 < x2:
                # b1 first
                if board[ny1][nx1] == "#":
                    ny1 -= dy
                    nx1 -= dx
                if board[ny2][nx2] == "#" or (ny2, nx2) == (ny1, nx1):
                    ny2 -= dy
                    nx2 -= dx
            else:
                # b2 first
                if board[ny2][nx2] == "#":
                    ny2 -= dy
                    nx2 -= dx
                if board[ny1][nx1] == "#" or (ny2, nx2) == (ny1, nx1):
                    ny1 -= dy
                    nx1 -= dx

        f(cnt + 1, (ny1, nx1), (ny2, nx2))


f(1, balls[0], balls[1])
print(ans if ans != 11 else -1)
