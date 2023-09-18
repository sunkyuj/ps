import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()
in_range = lambda y, x: 0 <= y < n and 0 <= x < n
answer = 0
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]


def unite(i, j):
    q = deque()
    visit[i][j] = 1
    q.append((i, j))
    s = 0
    cnt = 0
    u = []

    while q:
        y, x = q.popleft()
        u.append((y, x))
        s += A[y][x]
        cnt += 1

        for k in range(4):
            ny = y + dy[k]
            nx = x + dx[k]
            if in_range(ny, nx) and not visit[ny][nx] and l <= abs(A[y][x] - A[ny][nx]) <= r:
                q.append((ny, nx))
                visit[ny][nx] = 1

    if len(u) == 1:
        return False

    # 연합 내에서 이동
    res = s // cnt
    for y, x in u:
        A[y][x] = res
    return True


n, l, r = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]

# 2000만
while 1:  # 2000
    visit = [[0 for _ in range(n)] for _ in range(n)]  # 2500

    # 연합 만들기
    ud = {}
    moved = False
    for i in range(n):  # 2500
        for j in range(n):
            if not visit[i][j]:
                moved |= unite(i, j)

    if not moved:  # 이동 없음
        break

    answer += 1

print(answer)
