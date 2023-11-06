import sys

sys.setrecursionlimit(10**7)
n, m = map(int, input().split())
board = [input() for _ in range(n)]
visit = [[0 for _ in range(m)] for _ in range(n)]

ans = 0


def f(y, x, S):
    global ans
    if x == m:
        return f(y + 1, 0, S)
    if y == n:  # end
        ans = max(ans, S)
        return
    if visit[y][x]:
        return f(y, x + 1, S)

    visit[y][x] = 1

    f(y, x + 1, S + int(board[y][x]))

    # x+j ->
    end = x
    for j in range(x + 1, m):
        if visit[y][j]:
            break
        visit[y][j] = 1
        f(y, x + 1, S + int(board[y][x : j + 1]))
        end = j
    for j in range(x + 1, end + 1):
        visit[y][j] = 0

    # y+i v
    s = board[y][x]
    end = y
    for i in range(y + 1, n):
        if visit[i][x]:
            break
        visit[i][x] = 1
        s += board[i][x]
        f(y, x + 1, S + int(s))
        end = i
    for i in range(y + 1, end + 1):
        visit[i][x] = 0

    visit[y][x] = 0

    return


f(0, 0, 0)
print(ans)
