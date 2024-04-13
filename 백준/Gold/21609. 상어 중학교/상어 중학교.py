from collections import deque

BLACK = -1
RBW = 0
EMPTY = -999

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

ans = 0
in_range = lambda y, x: 0 <= y < n and 0 <= x < n
dydx = [(1, 0), (0, -1), (-1, 0), (0, 1)]


def rotate():
    global board
    tmp = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            tmp[n - 1 - j][i] = board[i][j]
    board = tmp


def gravity():
    for j in range(n):
        for i in range(n - 2, -1, -1):
            if board[i][j] >= RBW:
                land = i
                while land+1 < n and board[land + 1][j] == EMPTY:
                    land += 1
                board[i][j], board[land][j] = board[land][j], board[i][j]

def bfs(sy, sx):
    col = board[sy][sx]
    q = deque()
    q.append((sy, sx))
    vs = set()
    vs.add((sy, sx))

    cnt, rbw = 0, 0
    while q:
        y, x = q.popleft()
        cnt += 1
        if board[y][x] == RBW:
            rbw += 1

        for dy, dx in dydx:
            ny, nx = y + dy, x + dx
            if not in_range(ny, nx) or (ny, nx) in vs:
                continue
            if board[ny][nx] in (col, RBW):
                q.append((ny, nx))
                vs.add((ny, nx))
                if board[ny][nx] == col:
                    visit[ny][nx] = 1
    return (cnt, rbw, sy, sx), vs


while 1:
    visit = [[0 for _ in range(n)] for _ in range(n)]
    groups = []
    group_set = {}
    for i in range(n):
        for j in range(n):
            if not visit[i][j] and board[i][j] > 0:  # 색 있는 경우만
                data, vs = bfs(i, j)
                if data[0] >= 2:
                    groups.append(data)
                    group_set[data] = vs
    if not groups:
        break
    groups.sort(reverse=True)

    # 2. 제거 후 점수먹기
    cnt = 0
    for y, x in group_set[groups[0]]:
        board[y][x] = EMPTY
        cnt += 1
    ans += cnt ** 2

    # 3. 내리기
    gravity()
    # 4. 회전
    rotate()
    # 5. 내리기
    gravity()

print(ans)
