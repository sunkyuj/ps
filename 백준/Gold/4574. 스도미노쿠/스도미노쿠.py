def get_yx(loc):
    return ord(loc[0]) - ord("A"), int(loc[1]) - 1


def check_all():
    for i in range(9):
        for j in range(9):
            num = board[i][j]
            if num:
                rows[i][num] = 1
                cols[j][num] = 1
                sqrs[i // 3 + j % 3][num] = 1

    for i in range(9):
        if sum(rows[i]) < 45:
            return False
        if sum(cols[i]) < 45:
            return False
        if sum(sqrs[i]) < 45:
            return False
    return True


def check_right(y, x, a, b):
    # 쓸 숫자 (a,b)가 모두 rows[y]에 없어야함
    # 쓸 숫자 (a,b)가 각각 cols[x], cols[x+1]에 없어야함
    # 쓸 숫자 (a,b)가 각각 sqrs[y//3 + x%3], sqrs[y//3 + (x+1)%3]에 없어야함
    if rows[y][a] == 1 or rows[y][b] == 1:
        return False
    if cols[x][a] == 1 or cols[x + 1][b] == 1:
        return False
    if sqrs[y // 3 + x % 3] == 1 or sqrs[y // 3 + (x + 1) % 3] == 1:
        return False

    return True


def check_down(y, x, a, b):
    # 쓸 숫자 (a,b)가 각각 rows[y], rows[y+1]에 없어야함
    # 쓸 숫자 (a,b)가 모두 cols[x]에 없어야함
    # 쓸 숫자 (a,b)가 각각 sqrs[y//3 + x%3], sqrs[y//3 + (x+1)%3]에 없어야함
    if rows[y][a] == 1 or rows[y + 1][b] == 1:
        return False
    if cols[x][a] == 1 or cols[x][b] == 1:
        return False
    if sqrs[y // 3 + x % 3] == 1 or sqrs[(y + 1) // 3 + x % 3] == 1:
        return False
    return True


def check(y, x, ny, nx, a, b):
    rows[y][a] = 1
    rows[ny][b] = 1
    cols[x][a] = 1
    cols[nx][b] = 1
    sqrs[y // 3 + x % 3][a] = 1
    sqrs[ny // 3 + nx % 3][b] = 1
    board[y][x] = a
    board[ny][nx] = b


def uncheck(y, x, ny, nx, a, b):
    rows[y][a] = 0
    rows[ny][b] = 0
    cols[x][a] = 0
    cols[nx][b] = 0
    sqrs[y // 3 + x % 3][a] = 0
    sqrs[ny // 3 + nx % 3][b] = 0
    board[y][x] = 0
    board[ny][nx] = 0


def f(y, x):
    global solved

    if x == 9:
        x = 0
        y += 1
    if y == 9:
        for i in range(9):
            for j in range(9):
                print(board[i][j], end="")
            print()
        solved = True
        return solved

    if board[y][x]:  # filled
        return f(y, x + 1)

    if x + 1 < 9 and board[y][x + 1] == 0:  # right
        for i in range(len(dominos)):
            if visit[i]:
                continue
            a, b = dominos[i]
            if check_right(y, x, a, b):
                visit[i] = 1
                check(y, x, y, x + 1, a, b)
                if f(y, x + 1):
                    return True
                uncheck(y, x, y, x + 1, a, b)
                visit[i] = 0
            if check_right(y, x, b, a):
                visit[i] = 1
                check(y, x, y, x + 1, b, a)
                if f(y, x + 1):
                    return True
                uncheck(y, x, y, x + 1, b, a)
                visit[i] = 0
    if y + 1 < 9 and board[y + 1][x] == 0:  # down
        for i in range(len(dominos)):
            if visit[i]:
                continue
            a, b = dominos[i]
            if check_down(y, x, a, b):
                visit[i] = 1
                check(y, x, y + 1, x, a, b)
                if f(y, x + 1):
                    return True
                uncheck(y, x, y + 1, x, a, b)
                visit[i] = 0
            if check_down(y, x, b, a):
                visit[i] = 1
                check(y, x, y + 1, x, b, a)
                if f(y, x + 1):
                    return True
                uncheck(y, x, y + 1, x, b, a)
                visit[i] = 0

    return False


tc = 1
while 1:
    n = int(input())
    if n == 0:
        break
    board = [[0 for _ in range(9)] for _ in range(9)]
    dominos = [(i, j) for i in range(1, 10) for j in range(i + 1, 10)]
    visit = [0] * len(dominos)
    solved = False

    for i in range(n):
        num1, loc1, num2, loc2 = input().split()
        num1, num2 = int(num1), int(num2)
        y1, x1 = get_yx(loc1)
        y2, x2 = get_yx(loc2)
        board[y1][x1] = num1
        board[y2][x2] = num2
        domino = (num1, num2) if num1 < num2 else (num2, num1)
        dominos.remove(domino)

    locs = input().split()
    for i in range(1, 10):
        loc = locs[i - 1]
        y, x = get_yx(loc)
        board[y][x] = i

    # solve
    rows = [[0] * 10 for _ in range(9)]
    cols = [[0] * 10 for _ in range(9)]
    sqrs = [[0] * 10 for _ in range(9)]  # i,j = sqr[i*3 + j]
    check_all()
    print("Puzzle", tc)
    f(0, 0)
    tc += 1
