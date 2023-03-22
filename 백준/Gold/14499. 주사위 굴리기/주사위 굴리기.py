import sys

sys.setrecursionlimit(10**8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
in_range = lambda y, x: 0 <= y < n and 0 <= x < m

n, m, y, x, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
cmd = list(map(int, input().split()))
sero, garo = [0, 0, 0], [0, 0, 0]  # 가운데가 top
bottom = 0

for c in cmd:
    if c == 1:  # 동
        if not in_range(y, x + 1):
            continue
        x += 1
        garo[0], garo[1], garo[2], bottom = bottom, garo[0], garo[1], garo[2]
        sero[1] = garo[1]
    elif c == 2:  # 서
        if not in_range(y, x - 1):
            continue
        x -= 1
        garo[0], garo[1], garo[2], bottom = garo[1], garo[2], bottom, garo[0]
        sero[1] = garo[1]

    elif c == 3:  # 북
        if not in_range(y - 1, x):
            continue
        y -= 1
        sero[0], sero[1], sero[2], bottom = sero[1], sero[2], bottom, sero[0]
        garo[1] = sero[1]

    elif c == 4:  # 남
        if not in_range(y + 1, x):
            continue
        y += 1
        sero[0], sero[1], sero[2], bottom = bottom, sero[0], sero[1], sero[2]
        garo[1] = sero[1]

    if board[y][x]:  # not 0
        # copy to dice bottom
        bottom = board[y][x]
        board[y][x] = 0
    else:  # 0
        # paste at board from dice bottom
        board[y][x] = bottom

    print(sero[1])

"""

  2
4 1 3
  5
  6

동,서 (1,2) -> garo 회전하고 bottom을 garo에 넣기
북,남 (3,4) -> sero 회전하고 bottom을 sero에 넣기

"""
