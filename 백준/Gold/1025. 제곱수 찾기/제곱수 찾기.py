n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]
doubles = {i**2 for i in range(31624)}  # 9자리 수 제곱수는 다 나옴

in_range = lambda y, x: 0 <= y < n and 0 <= x < m

# 내려가기만 하면 됨, 마지막에 숫자 뒤집으면 그만

ans = -1


def start(y, x):
    for i in range(y, n):
        for j in range(m):
            if i == y and j <= x:
                continue
            dy = i - y
            dx = j - x
            get(y, x, dy, dx)


def get(y, x, dy, dx):
    global ans
    nums = []
    while in_range(y, x):
        nums.append(board[y][x])
        y += dy
        x += dx
        num, rnum = int("".join(nums)), int("".join(reversed(nums)))
        if num in doubles:
            ans = max(ans, num)
        if rnum in doubles:
            ans = max(ans, rnum)


for i in range(n):
    for j in range(m):
        if int(board[i][j]) in doubles:
            ans = max(ans, int(board[i][j]))
        start(i, j)

print(ans)
