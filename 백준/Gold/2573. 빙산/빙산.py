import queue
import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

q = deque()


def bfs(i, j):

    q.append((i, j))

    while q:
        y, x = q.popleft()

        water = 0
        for k in range(4):
            ny, nx = y + dy[k], x + dx[k]
            if not (0 <= ny < h and 0 <= nx < w):
                continue
            if board[ny][nx] == 0:
                water += 1
            if not visit[ny][nx] and board[ny][nx]:
                q.append((ny, nx))
                visit[ny][nx] = 1
        if water:
            update.add((y, x, max(0, board[y][x] - water)))
    return 1


h, w = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(h)]
ans = 0

# h, w = 300, 300
# board = [[10 if j not in (0, 299) else 0 for j in range(300)] for _ in range(300)]
# board[0], board[-1] = [0 for _ in range(300)], [0 for _ in range(300)]

while 1:

    cnt = 0
    visit = [[0 for _ in range(w)] for _ in range(h)]
    update = set()
    for i in range(h):
        for j in range(w):
            if not visit[i][j] and board[i][j]:
                visit[i][j] = 1
                cnt += bfs(i, j)

    for y, x, ice in update:
        board[y][x] = ice

    if cnt != 1:  # 다 녹거나, 올해 전에 덩이 나뉨
        ans = 0 if cnt == 0 else ans
        break
    ans += 1  # 덩이 안 나위었으니 1년 추가


print(ans)
