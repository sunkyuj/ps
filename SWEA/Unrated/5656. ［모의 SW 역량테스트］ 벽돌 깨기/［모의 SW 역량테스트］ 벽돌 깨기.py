from copy import deepcopy
from collections import deque

dy, dx = [1, -1, 0, 0], [0, 0, 1, -1]
q = deque()


def explode(y, x, size, b):
    b[y][x] = 0
    for i in range(1, size):
        if in_range(y + i, 0) and b[y + i][x]:
            q.append((y + i, x, b[y + i][x]))
            b[y + i][x] = 0
    for i in range(1, size):
        if in_range(y - i, 0) and b[y - i][x]:
            q.append((y - i, x, b[y - i][x]))
            b[y - i][x] = 0
    for i in range(1, size):
        if in_range(0, x + i) and b[y][x + i]:
            q.append((y, x + i, b[y][x + i]))
            b[y][x + i] = 0
    for i in range(1, size):
        if in_range(0, x - i) and b[y][x - i]:
            q.append((y, x - i, b[y][x - i]))
            b[y][x - i] = 0


def fall(b):
    for j in range(w):
        y = h - 1
        for i in range(h - 1, -1, -1):
            if b[i][j]:
                block = b[i][j]
                b[i][j] = 0
                b[y][j] = block
                y -= 1


def f(cnt, b):

    if cnt == n:
        global ans
        blocks = 0
        for r in b:
            zcount = r.count(0)
            blocks += w - zcount
        ans = min(ans, blocks)
        return

    for x in range(w):
        new_b = deepcopy(b)

        # y,x에서 떨어질 y위치 찾기
        y = 0
        while y < h and new_b[y][x] == 0:
            y += 1
        # print("\t" * cnt, y, x)
        # if (cnt, y, x) == (1, 2, 2):
        #     print("!!!!")

        if y != h:  # 빈곳에 안 떨어짐
            # 터지기 (연쇄적으로)
            q.append((y, x, new_b[y][x]))
            while q:
                cy, cx, size = q.popleft()
                explode(cy, cx, size, new_b)

            # 벽돌 정렬
            fall(new_b)

        # 다음 상황
        f(cnt + 1, new_b)
    return


for tc in range(int(input())):
    ans = 12 * 15
    n, w, h = map(int, input().split())
    in_range = lambda y, x: 0 <= y < h and 0 <= x < w

    board = [list(map(int, input().split())) for _ in range(h)]
    f(0, board)

    print(f"#{tc+1} {ans}")

"""

2
3 10 10
0 0 0 0 0 0 0 0 0 0
1 0 1 0 1 0 0 0 0 0
1 0 3 0 1 1 0 0 0 1
1 1 1 0 1 2 0 0 0 9
1 1 4 0 1 1 0 0 1 1
1 1 4 1 1 1 2 1 1 1
1 1 5 1 1 1 1 2 1 1
1 1 6 1 1 1 1 1 2 1
1 1 1 1 1 1 1 1 1 5
1 1 7 1 1 1 1 1 1 1
2 9 10
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
1 1 0 0 1 0 0 0 0
1 1 0 1 1 1 0 1 0
1 1 0 1 1 1 0 1 0
1 1 1 1 1 1 1 1 0
1 1 3 1 6 1 1 1 1
1 1 1 1 1 1 1 1 1

"""
