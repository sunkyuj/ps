n, r = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(2**n)]
tmp = [[0 for _ in range(2**n)] for _ in range(2**n)]


# 내부
def f1(sy, sx, unit):  # 내부 상하반전
    for y in range(unit):
        for x in range(unit):
            tmp[unit - 1 - y][x] = board[y + sy][x + sx]


def f2(sy, sx, unit):  # 내부 좌우반전
    for y in range(unit):
        for x in range(unit):
            tmp[y][unit - 1 - x] = board[y + sy][x + sx]


def f3(sy, sx, unit):  # 내부 오90 회전
    for y in range(unit):
        for x in range(unit):
            tmp[x][unit - 1 - y] = board[y + sy][x + sx]


def f4(sy, sx, unit):  # 내부 왼90 회전
    for y in range(unit):
        for x in range(unit):
            tmp[unit - 1 - x][y] = board[y + sy][x + sx]


# 외부
def f5(sy, sx, unit):  # 외부 상하반전
    out_n = 2**n // unit
    out_y, out_x = sy // unit, sx // unit
    for y in range(unit):
        for x in range(unit):
            tmp[(out_n - 1 - out_y) * unit + y][x + sx] = board[y + sy][x + sx]


def f6(sy, sx, unit):  # 외부 좌우반전
    out_n = 2**n // unit
    out_y, out_x = sy // unit, sx // unit
    for y in range(unit):
        for x in range(unit):
            tmp[y + sy][(out_n - 1 - out_x) * unit + x] = board[y + sy][x + sx]


def f7(sy, sx, unit):  # 외부 오90 회전
    out_n = 2**n // unit
    out_y, out_x = sy // unit, sx // unit
    for y in range(unit):
        for x in range(unit):
            tmp[out_x * unit + y][(out_n - 1 - out_y) * unit + x] = board[y + sy][x + sx]


def f8(sy, sx, unit):  # 외부 왼90 회전
    out_n = 2**n // unit
    out_y, out_x = sy // unit, sx // unit
    for y in range(unit):
        for x in range(unit):
            tmp[(out_n - 1 - out_x) * unit + y][out_y * unit + x] = board[y + sy][x + sx]


fs = [f1, f2, f3, f4, f5, f6, f7, f8]


def slice(cmd, l):
    unit = 2**l
    for si in range(0, 2**n, unit):
        for sj in range(0, 2**n, unit):
            fs[cmd - 1](si, sj, unit)

            if cmd <= 4:  # 내부
                for i in range(unit):
                    for j in range(unit):
                        board[i + si][j + sj] = tmp[i][j]
    if cmd > 4:  # 외부
        for i in range(2**n):
            board[i] = tmp[i][:]


for _ in range(r):
    cmd, l = map(int, input().split())
    slice(cmd, l)

for r in board:
    for c in r:
        print(c, end=" ")
    print()

# 각 부분을 (내부 변화 o)
# 1 상하 반전
# 2 좌우 반전
# 3 오른쪽 회전 90도
# 4 왼쪽 회전 90도

# 부분을 통으로 (내부 변화 x)
# 5 상하 반전
# 6 좌우 반전
# 7 오른쪽 회전 90도
# 8 왼쪽 회전 90도
