import sys

sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()
# idx = lambda x: ord(x) - 65
in_range = lambda y, x: 0 <= y < r and 0 <= x < c

d = [(1, 0), (0, 1), (-1, 0), (0, -1)]

r, c = map(int, input().split())
board = [input() for _ in range(r)]
paths = [[set() for _ in range(c)] for _ in range(r)]
max_cnt = 0
has_alp = {}.fromkeys("ABCDEFGHIJKLMNOPQRSTUVWXYZ")


def f(y, x, path: str):
    global max_cnt
    max_cnt = max(max_cnt, len(path))

    for dy, dx in d:
        ny, nx = y + dy, x + dx
        if (
            in_range(ny, nx)
            and not has_alp[board[ny][nx]]
            and path + board[ny][nx] not in paths[ny][nx]
        ):
            paths[ny][nx].add(path + board[ny][nx])
            has_alp[board[ny][nx]] = 1
            f(ny, nx, path + board[ny][nx])
            has_alp[board[ny][nx]] = 0


has_alp[board[0][0]] = 1
paths[0][0].add(board[0][0])
f(0, 0, board[0][0])
print(max_cnt)