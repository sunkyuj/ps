from collections import deque

h, w = map(int, input().split())
in_range = lambda y, x: 0 <= y < h and 0 <= x < w

board = [list(map(int, input().split())) for _ in range(h)]
time = 0
prev, rem = 0, 0
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]


def clustering(i, j):
    global rem
    q = deque()
    q.append((i, j))
    visit[i][j] = 1

    contact = set()

    while q:
        y, x = q.popleft()
        root[y][x] = (i, j)
        if board[y][x]:
            rem += 1

        for k in range(4):
            ny = y + dy[k]
            nx = x + dx[k]
            if not in_range(ny, nx):
                continue

            if board[ny][nx] == board[y][x] and not visit[ny][nx]:
                visit[ny][nx] = 1
                q.append((ny, nx))

            # 치즈가 공기 또는 구멍이랑 접촉
            if board[y][x] == 1 and root[ny][nx] == (0, 0):
                contact.add((y, x))

    return contact


while 1:
    visit = [[0 for _ in range(w)] for _ in range(h)]
    root = [[(i, j) for j in range(w)] for i in range(h)]  # root 0,0 이면 외부임

    prev = rem
    rem = 0
    cand = set()
    for i in range(h):
        for j in range(w):
            if not visit[i][j]:
                contact = clustering(i, j)
                cand.update(contact)
    if not cand:
        break

    # 치즈 녹음
    for y, x in cand:
        board[y][x] = 0
    time += 1


print(time)
print(prev)
