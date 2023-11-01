r, c = map(int, input().split())
board = [list(input()) for _ in range(r)]

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]  # v > ^ <
in_range = lambda y, x: 0 <= y < r and 0 <= x < c

my, mx, zy, zx = -1, -1, -1, -1
for i in range(r):
    for j in range(c):
        if board[i][j] == "M":
            my, mx = i, j


def next_dir(cur_dir, nxt):
    ny, nx = nxt

    # +
    if board[ny][nx] == "+":
        return cur_dir
    # |
    elif board[ny][nx] == "|":
        if cur_dir in (0, 2):
            return cur_dir
    # -
    elif board[ny][nx] == "-":
        if cur_dir in (1, 3):
            return cur_dir
    # 1 2 3 4
    # 1: r / 2: ㄴ / 3: j / 4: ㄱ
    elif board[ny][nx] == "1":  # r
        if cur_dir == 2:
            return 1
        if cur_dir == 3:
            return 0
    elif board[ny][nx] == "2":  # ㄴ
        if cur_dir == 0:
            return 1
        if cur_dir == 3:
            return 2
    elif board[ny][nx] == "3":  # j
        if cur_dir == 1:
            return 2
        if cur_dir == 0:
            return 3
    elif board[ny][nx] == "4":  # ㄱ
        if cur_dir == 1:
            return 0
        if cur_dir == 2:
            return 3

    return -1


for k in range(4):
    ny, nx = my + dy[k], mx + dx[k]
    nd = -1
    if in_range(ny, nx) and board[ny][nx] != ".":
        nd = next_dir(k, (ny, nx))
        if nd != -1:
            break

while 1:
    y, x, d = ny, nx, nd
    ny, nx = y + dy[d], x + dx[d]
    if board[ny][nx] == ".":
        cand = []
        for pipe in ("|", "-", "1", "2", "3", "4"):
            board[ny][nx] = pipe
            nd = next_dir(d, (ny, nx))
            nny, nnx = ny + dy[nd], nx + dx[nd]
            if (nny, nnx) == (y, x):
                continue
            if in_range(nny, nnx) and board[nny][nnx] != ".":
                nnd = next_dir(nd, (nny, nnx))
                if nnd != -1:
                    cand.append(pipe)

        # print(cand)
        if len(cand) >= 2:
            print(ny + 1, nx + 1, "+")
        else:
            print(ny + 1, nx + 1, cand[0])
        exit()

    nd = next_dir(d, (ny, nx))


