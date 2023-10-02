# ↑, ↖, ←, ↙, ↓, ↘, →, ↗
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, -1, -1, -1, 0, 1, 1, 1]
board = [[0, 0, 0, 0] for _ in range(4)]
ans = 0
in_range = lambda y, x: 0 <= y < 4 and 0 <= x < 4


def copy_board(bd):
    new = [[bd[i][j] for j in range(4)] for i in range(4)]
    return new


def move_fish(num, bd):
    for y in range(4):  # 4
        for x in range(4):  # 4
            if bd[y][x][0] == num:
                dir = bd[y][x][1]
                for k in range(8):  # 8
                    new_dir = (dir + k - 1) % 8
                    ny, nx = y + dy[new_dir], x + dx[new_dir]
                    if not in_range(ny, nx) or bd[ny][nx][0] == "s":
                        continue
                    bd[y][x] = (bd[y][x][0], new_dir + 1)
                    bd[y][x], bd[ny][nx] = bd[ny][nx], bd[y][x]
                    return


def f(bd, sy, sx, sdir, point):
    global ans
    ans = max(ans, point)

    # 물고기 이동 (작은순으로)
    # 2048
    for num in range(1, 17):  # 16
        move_fish(num, bd)

    # 상어 이동
    for k in range(1, 4):
        ny = sy + dy[sdir - 1] * k
        nx = sx + dx[sdir - 1] * k
        if not in_range(ny, nx):
            break
        if bd[ny][nx][0]:  # 물고기임
            new_bd = copy_board(bd)
            num, dir = new_bd[ny][nx]
            new_bd[ny][nx] = (new_bd[sy][sx][0], dir)
            new_bd[sy][sx] = (0, 0)

            f(new_bd, ny, nx, dir, point + num)


for i in range(4):
    a0, b0, a1, b1, a2, b2, a3, b3 = map(int, input().split())
    board[i][0] = (a0, b0)
    board[i][1] = (a1, b1)
    board[i][2] = (a2, b2)
    board[i][3] = (a3, b3)

# 처음에 0,0 먹음
num, dir = board[0][0]
board[0][0] = ("s", dir)
f(board, 0, 0, dir, num)

print(ans)
