from collections import deque

board = [list(input()) for _ in range(8)]
dydx = [
    (0, 0),
    (1, 0),
    (0, 1),
    (-1, 0),
    (0, -1),
    (1, 1),
    (1, -1),
    (-1, 1),
    (-1, -1),
]
in_range = lambda y, x: 0 <= y < 8 and 0 <= x < 8

level = 0
q = deque()
q.append((7, 0, 0))  # y,x,lv
while q:
    y, x, lv = q.popleft()

    if lv > level:
        level = lv
        board.pop()
        board.insert(0, list("." * 8))

    if board[y][x] == "#":
        continue

    if lv == 8:
        print(1)
        exit()

    for dy, dx in dydx:
        ny, nx = y + dy, x + dx
        if in_range(ny, nx) and board[ny][nx] == ".":
            q.append((ny, nx, lv + 1))

print(0)
