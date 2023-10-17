from collections import deque

n, q = map(int, input().split())
bn = 2**n
board = [list(map(int, input().split())) for _ in range(bn)]
ls = list(map(int, input().split()))
in_range = lambda y, x: 0 <= y < bn and 0 <= x < bn
tmp = [[0 for _ in range(bn)] for _ in range(bn)]


def rotate(y, x, ey, ex):
    gap = ey - y
    for i in range(y, ey):
        for j in range(x, ex):
            tmp[j - x][gap - (i - y) - 1] = board[i][j]

    for i in range(gap):
        for j in range(gap):
            board[i + y][j + x] = tmp[i][j]


for l in ls:  # 1000
    gap = 2**l
    # 회전
    for i in range(0, bn, gap):
        for j in range(0, bn, gap):
            rotate(i, j, i + gap, j + gap)

    # 얼음 녹기 16000
    melt = set()
    for i in range(bn):  # 64
        for j in range(bn):  # 64
            if board[i][j] == 0:
                continue
            cnt = 0
            for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                ny, nx = i + dy, j + dx
                if in_range(ny, nx) and board[ny][nx]:
                    cnt += 1
            if cnt < 3:
                melt.add((i, j))
    for y, x in melt:
        board[y][x] -= 1

ans_sum = 0
ans_cnt = 0
visit = [[0 for _ in range(bn)] for _ in range(bn)]
for i in range(bn):
    for j in range(bn):
        if board[i][j] and not visit[i][j]:
            q = deque()
            q.append((i, j))
            visit[i][j] = 1
            cnt = 0
            while q:
                y, x = q.popleft()
                ans_sum += board[y][x]
                cnt += 1
                for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                    ny, nx = y + dy, x + dx
                    if in_range(ny, nx) and board[ny][nx] and not visit[ny][nx]:
                        q.append((ny, nx))
                        visit[ny][nx] = 1
            ans_cnt = max(ans_cnt, cnt)

print(ans_sum)
print(ans_cnt)


