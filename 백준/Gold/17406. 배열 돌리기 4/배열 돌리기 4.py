from itertools import permutations
from copy import deepcopy

n, m, k = map(int, input().split())
board = [[0] + list(map(int, input().split())) for _ in range(n)]
board.insert(0, [0] * m)
info = [list(map(int, input().split())) for _ in range(k)]

ans = 999999999


def spin(board, r, c, s):
    si, sj = r - s, c - s
    ei, ej = r + s, c + s
    while (si, sj) != (ei, ej):
        tmp = board[si][sj]
        for j in range(sj + 1, ej + 1):
            board[si][j], tmp = tmp, board[si][j]
        for i in range(si + 1, ei + 1):
            board[i][ej], tmp = tmp, board[i][ej]
        for j in range(ej - 1, sj - 1, -1):
            board[ei][j], tmp = tmp, board[ei][j]
        for i in range(ei - 1, si - 1, -1):
            board[i][sj], tmp = tmp, board[i][sj]
        si += 1
        sj += 1
        ei -= 1
        ej -= 1

    # for r in board[1:]:
    #     print(r[1:])
    # print()


def get_val(board):
    val = 999999999
    for r in board[1:]:
        val = min(val, sum(r))
    return val


for ps in permutations(info):
    nboard = deepcopy(board)
    for p in ps:
        r, c, s = p
        spin(nboard, r, c, s)
    ans = min(ans, get_val(nboard))

print(ans)
