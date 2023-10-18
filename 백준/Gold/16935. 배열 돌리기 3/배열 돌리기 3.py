n, m, r = map(int, input().split())
board = [[0 for _ in range(max(n, m))] for _ in range(max(n, m))]
for i in range(n):
    row = list(map(int, input().split()))
    for j in range(m):
        board[i][j] = row[j]
commands = list(map(int, input().split()))
tmp = [[0 for _ in range(max(n, m))] for _ in range(max(n, m))]


def f1():
    for i in range(n):
        for j in range(m):
            tmp[n - 1 - i][j] = board[i][j]


def f2():
    for i in range(n):
        for j in range(m):
            tmp[i][m - 1 - j] = board[i][j]


def f3():  # 90도 시계방향 회전
    global n, m
    for i in range(n):
        for j in range(m):
            tmp[j][n - 1 - i] = board[i][j]
    n, m = m, n


def f4():  # 90도 반시계방향 회전
    global n, m
    for i in range(n):
        for j in range(m):
            tmp[m - 1 - j][i] = board[i][j]
    n, m = m, n


def f5():  # 4분할 후 시계방향
    # 1 -> 2
    for i in range(n // 2):
        for j in range(m // 2):
            tmp[i][j + m // 2] = board[i][j]
    # 2 -> 3
    for i in range(n // 2):
        for j in range(m // 2, m):
            tmp[i + n // 2][j] = board[i][j]
    # 3 -> 4
    for i in range(n // 2, n):
        for j in range(m // 2, m):
            tmp[i][j - m // 2] = board[i][j]
    # 4 -> 1
    for i in range(n // 2, n):
        for j in range(m // 2):
            tmp[i - n // 2][j] = board[i][j]


def f6():  # 4분할 후 반시계방향
    # 1 -> 4
    for i in range(n // 2):
        for j in range(m // 2):
            tmp[i + n // 2][j] = board[i][j]
    # 2 -> 1
    for i in range(n // 2):
        for j in range(m // 2, m):
            tmp[i][j - m // 2] = board[i][j]
    # 3 -> 2
    for i in range(n // 2, n):
        for j in range(m // 2, m):
            tmp[i - n // 2][j] = board[i][j]
    # 4 -> 3
    for i in range(n // 2, n):
        for j in range(m // 2):
            tmp[i][j + m // 2] = board[i][j]


def adjust():  # 적용
    for i in range(n):
        for j in range(m):
            board[i][j] = tmp[i][j]


for cmd in commands:
    if cmd == 1:  # 상하 반전
        f1()
    elif cmd == 2:  # 좌우 반전
        f2()
    elif cmd == 3:  # 90도 시계방향 회전
        f3()
    elif cmd == 4:  # 90도 반시계방향 회전
        f4()
    elif cmd == 5:  # 4분할 후 시계방향
        f5()
    elif cmd == 6:  # 4분할 후 반시계방향
        f6()
    adjust()

for i in range(n):
    for j in range(m):
        print(board[i][j], end=" ")
    print()
