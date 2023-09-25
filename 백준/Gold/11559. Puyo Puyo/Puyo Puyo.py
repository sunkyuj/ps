from collections import deque

input_board = [list(input()) for _ in range(12)]
board = [["." for _ in range(12)] for _ in range(6)]
in_range = lambda y, x: 0 <= y < 6 and 0 <= x < 12

for i in range(12):
    for j in range(6):
        board[j][11 - i] = input_board[i][j]


def bfs(i, j):
    s = set()
    q = deque()
    q.append((i, j))
    visit[i][j] = 1
    color = board[i][j]
    while q:
        y, x = q.popleft()
        s.add((y, x))
        for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            ny = y + dy
            nx = x + dx
            if in_range(ny, nx) and not visit[ny][nx] and board[ny][nx] == color:
                q.append((ny, nx))
                visit[ny][nx] = 1

    return s if len(s) >= 4 else set()


ans = 0
while 1:
    visit = [[0 for _ in range(12)] for _ in range(6)]
    # 터뜨릴것 찾기
    pop_set = set()
    for i in range(6):
        for j in range(12):
            if board[i][j] != ".":
                pop_set.update(bfs(i, j))
    if pop_set:
        ans += 1
        # 터뜨리기 (여러개여도 1로 카운트)
        for y, x in pop_set:
            board[y][x] = "."
    else:
        break

    # 왼쪽 붙이기
    for i in range(6):
        gnd = 0
        for j in range(12):
            if board[i][j] != ".":
                board[i][gnd], board[i][j] = board[i][j], board[i][gnd]
                gnd += 1
            else:
                continue


print(ans)
