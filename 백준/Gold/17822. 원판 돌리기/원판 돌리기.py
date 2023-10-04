from collections import deque

n, m, t = map(int, input().split())
board = [None] + [deque(map(int, input().split())) for _ in range(n)]
# in_range = lambda y, x: 1 <= y <= n and 0 <= x < m


# 회전
for _ in range(t):
    x, d, k = map(int, input().split())
    for i in range(x, n + 1, x):  # x의 배수 원판 회전
        for _ in range(k):
            if d == 0:  # 시계
                board[i].appendleft(board[i].pop())
            else:  # 반시계
                board[i].append(board[i].popleft())

    rm = set()
    visit = [None] + [[0 for _ in range(m)] for _ in range(n)]
    s = 0
    cnt = 0
    for y in range(1, n + 1):
        for x in range(m):
            if board[y][x]:
                s += board[y][x]
                cnt += 1
                for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                    ny, nx = y + dy, (x + dx) % m
                    if 1 <= ny <= n:
                        if board[y][x] == board[ny][nx]:
                            rm.add((y, x))
                            rm.add((ny, nx))
    if not rm:
        if cnt == 0:
            continue
        avg = s / cnt

        for y in range(1, n + 1):
            for x in range(m):
                if board[y][x]:
                    if board[y][x] > avg:
                        board[y][x] -= 1
                    elif board[y][x] < avg:
                        board[y][x] += 1

        continue

    for y, x in rm:
        s -= board[y][x]
        cnt -= 1
        board[y][x] = 0


ans = 0
for y in range(1, n + 1):
    for x in range(m):
        ans += board[y][x]
print(ans)
