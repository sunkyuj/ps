n = int(input())
board = [list(input()) for _ in range(n)]


def get_max():  # 100
    M = 0
    # ->
    for i in range(n):
        r_max = 0
        cur, prev = 0, ""
        for j in range(n):
            if board[i][j] == prev:
                cur += 1
            else:
                cur = 1
            prev = board[i][j]
            r_max = max(r_max, cur)
        M = max(M, r_max)
    # v
    for j in range(n):
        c_max = 0
        cur, prev = 0, ""
        for i in range(n):
            if board[i][j] == prev:
                cur += 1
            else:
                cur = 1
            prev = board[i][j]
            c_max = max(c_max, cur)
        M = max(M, c_max)

    return M


ans = 0
for i in range(n):
    for j in range(n):
        if j + 1 < n and board[i][j] != board[i][j + 1]:
            board[i][j], board[i][j + 1] = board[i][j + 1], board[i][j]
            ans = max(ans, get_max())
            board[i][j], board[i][j + 1] = board[i][j + 1], board[i][j]

        if i + 1 < n and board[i][j] != board[i + 1][j]:
            board[i][j], board[i + 1][j] = board[i + 1][j], board[i][j]
            ans = max(ans, get_max())
            board[i][j], board[i + 1][j] = board[i + 1][j], board[i][j]
print(ans)
