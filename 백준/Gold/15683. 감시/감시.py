n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
ans = 9999999
"""
1 4개
2 2개
3 4개
4 4개
5 1개

0 - 빈공간  /  6 - 벽
"""


def up(y, x):
    s = set()
    for i in range(y, -1, -1):
        if board[i][x] == 6:
            break
        s.add((i, x))

    return s


def down(y, x):
    s = set()
    for i in range(y, n):
        if board[i][x] == 6:
            break
        s.add((i, x))

    return s


def right(y, x):
    s = set()
    for j in range(x, m):
        if board[y][j] == 6:
            break
        s.add((y, j))

    return s


def left(y, x):
    s = set()
    for j in range(x, -1, -1):
        if board[y][j] == 6:
            break
        s.add((y, j))

    return s


def f(cam_idx, s):
    if cam_idx == len(cams):  # searched all cams
        global ans, walls
        ans = min(ans, n * m - walls - len(s))
        return

    cam_type, y, x = cams[cam_idx]

    if cam_type == 1:
        f(cam_idx + 1, s | up(y, x))
        f(cam_idx + 1, s | down(y, x))
        f(cam_idx + 1, s | right(y, x))
        f(cam_idx + 1, s | left(y, x))

    elif cam_type == 2:
        f(cam_idx + 1, s | up(y, x) | down(y, x))
        f(cam_idx + 1, s | right(y, x) | left(y, x))

    elif cam_type == 3:
        f(cam_idx + 1, s | up(y, x) | right(y, x))
        f(cam_idx + 1, s | right(y, x) | down(y, x))
        f(cam_idx + 1, s | down(y, x) | left(y, x))
        f(cam_idx + 1, s | left(y, x) | up(y, x))

    elif cam_type == 4:
        f(cam_idx + 1, s | up(y, x) | right(y, x) | down(y, x))
        f(cam_idx + 1, s | right(y, x) | down(y, x) | left(y, x))
        f(cam_idx + 1, s | down(y, x) | left(y, x) | up(y, x))
        f(cam_idx + 1, s | left(y, x) | up(y, x) | right(y, x))

    elif cam_type == 5:
        f(cam_idx + 1, s | up(y, x) | right(y, x) | down(y, x) | left(y, x))


cams = []  # (cam_type, y, x)
walls = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == 6:  # wall
            walls += 1
        elif 0 < board[i][j]:  # cam
            cams.append((board[i][j], i, j))


f(0, set())
print(ans)
