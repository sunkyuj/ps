n, m, k = map(int, input().split())
in_range = lambda y, x: 0 <= y < n and 0 <= x < n

board = [list(map(int, input().split())) for _ in range(n)]
smell = [[[board[i][j], 0] for j in range(n)] for i in range(n)]  # smell[i][j] = [shark_num,t]
sdirs = [0] + list(map(int, input().split()))  # 초기 상어 방향
shark_info = [[-1, -1, -1] for _ in range(m + 1)]  # [y,x,dir]
for i in range(n):
    for j in range(n):
        if board[i][j]:
            shark_info[board[i][j]] = [i, j, sdirs[board[i][j]]]


dydx = [[0, 0], [-1, 0], [1, 0], [0, -1], [0, 1]]  # -, 위, 아래, 왼, 오

priority = [[None] for _ in range(m + 1)]
for i in range(1, m + 1):
    priority[i].append(list(map(int, input().split())))
    priority[i].append(list(map(int, input().split())))
    priority[i].append(list(map(int, input().split())))
    priority[i].append(list(map(int, input().split())))


def find_pri(pri, cand):
    for dir in pri:
        for cy, cx, cd in cand:
            if cd == dir:
                return (cy, cx, cd)


for t in range(1, 1001):  # 1000
    # 이동하기 (냄새 없는칸 > 자기 냄새 칸) / 여러개인 경우 우선순위를 따름
    for i in range(1, m + 1):  # 400
        y, x, dir = shark_info[i]
        if [y, x, dir] == [-1, -1, -1]:  # dead shark
            continue
        pri = priority[i][dir]
        no_smell = []
        my_smell = []
        for ndir in range(1, 5):
            dy, dx = dydx[ndir]
            ny, nx = y + dy, x + dx
            if in_range(ny, nx):
                nsmell, nsmell_t = smell[ny][nx]
                if nsmell == 0 or nsmell_t + k < t:  # no smell
                    no_smell.append((ny, nx, ndir))
                elif nsmell == i:  # my smell
                    my_smell.append((ny, nx, ndir))
        if no_smell:
            ny, nx, nd = find_pri(pri, no_smell)
            shark_info[i] = [ny, nx, nd]
            board[y][x] = 0
        elif my_smell:
            ny, nx, nd = find_pri(pri, my_smell)
            shark_info[i] = [ny, nx, nd]
            board[y][x] = 0

    # 겹쳐있으면 번호가 min인 상어만 남기고 없애기
    for i in range(1, m + 1):  # 400
        if shark_info[i] == [-1, -1, -1]:
            continue
        y, x, dir = shark_info[i]
        if board[y][x]:  # 이미 상어 있음
            shark_info[i] = [-1, -1, -1]
        else:
            board[y][x] = i
            # 상어마다 자기 냄새(k동안 지속) 뿌리기
            smell[y][x] = [i, t]

    cnt = 0
    for i in range(1, m + 1):
        if shark_info[i] != [-1, -1, -1]:
            cnt += 1
    if cnt == 1:
        print(t)
        exit()

print(-1)
