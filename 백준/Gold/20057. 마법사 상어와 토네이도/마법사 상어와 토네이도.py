n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
in_range = lambda y, x: 0 <= y < n and 0 <= x < n
dy = [0, 1, 0, -1]
dx = [-1, 0, 1, 0]


def move_sand(y, x, p):
    if in_range(y, x):
        board[y][x] += p
        return 0
    return p


def spread(y, x, dir):
    sand = board[y + dy[dir]][x + dx[dir]]
    board[y + dy[dir]][x + dx[dir]] = 0
    p1, p2, p5, p7, p10 = map(int, [0.01 * sand, 0.02 * sand, 0.05 * sand, 0.07 * sand, 0.1 * sand])
    a = sand - p5 - (p1 + p2 + p7 + p10) * 2

    out = 0

    # x에 위치
    # 1%
    out += move_sand(y + dy[(dir - 1) % 4], x + dx[(dir - 1) % 4], p1)
    out += move_sand(y + dy[(dir + 1) % 4], x + dx[(dir + 1) % 4], p1)

    # y에 위치
    y += dy[dir]
    x += dx[dir]
    # 7%
    out += move_sand(y + dy[(dir - 1) % 4], x + dx[(dir - 1) % 4], p7)
    out += move_sand(y + dy[(dir + 1) % 4], x + dx[(dir + 1) % 4], p7)
    # 2%
    out += move_sand(y + dy[(dir - 1) % 4] * 2, x + dx[(dir - 1) % 4] * 2, p2)
    out += move_sand(y + dy[(dir + 1) % 4] * 2, x + dx[(dir + 1) % 4] * 2, p2)

    # a에 위치
    y += dy[dir]
    x += dx[dir]
    out += move_sand(y, x, a)
    # a 다음
    out += move_sand(y + dy[dir], x + dx[dir], p5)
    # 10%
    out += move_sand(y + dy[(dir - 1) % 4], x + dx[(dir - 1) % 4], p10)
    out += move_sand(y + dy[(dir + 1) % 4], x + dx[(dir + 1) % 4], p10)

    return out


y, x = n // 2, n // 2
l = 1
lcnt = 0  # 가로+1 세로+1
turn_cnt = 0
dir = 0
ans = 0
while (y, x) != (0, 0):
    ans += spread(y, x, dir)
    y += dy[dir]
    x += dx[dir]
    lcnt += 1
    if lcnt == l:  # 길이만큼 이동시 방향전환
        dir = (dir + 1) % 4
        turn_cnt += 1
        lcnt = 0
    if turn_cnt == 2:  # 두번 방향전환 하면, 길이 1 증가
        turn_cnt = 0
        l += 1

print(ans)
