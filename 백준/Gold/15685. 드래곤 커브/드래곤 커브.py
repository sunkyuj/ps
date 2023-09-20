# dc[4][11]: [0 1 2 1 ...]
dc = [[[] for _ in range(11)] for _ in range(4)]
dc[0][0] = [0]
dc[1][0] = [1]
dc[2][0] = [2]
dc[3][0] = [3]

for d in range(4):
    for g in range(1, 11):
        prev = dc[d][g - 1]
        new = []
        for x in reversed(prev):
            y = (x + 2) % 4
            new.append((y - 1) % 4)
        dc[d][g] = prev + new


n = int(input())
info = [list(map(int, input().split())) for _ in range(n)]
# info[i] = x, y, d ,g
dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]
in_range = lambda x, y: 0 <= x <= 100 and 0 <= y <= 100

board = [[0 for _ in range(101)] for _ in range(101)]
for x, y, d, g in info:
    curve = dc[d][g]
    cx, cy = x, y
    board[cx][cy] = 1
    for dir in curve:
        cx += dx[dir]
        cy += dy[dir]
        if in_range(cx, cy):
            board[cx][cy] = 1

ans = 0
for x in range(100):
    for y in range(100):
        if board[x][y] + board[x + 1][y] + board[x][y + 1] + board[x + 1][y + 1] == 4:
            ans += 1

print(ans)


"""
d = 0
dc[0] = (0,0) (1,0)
dc[k] = dc[k-1]의 끝에 90도 돌린 dc[k-1] 부착

dc[0] = ->
dc[1] = -> ^
dc[2] = -> ^ <- ^


-> : v      0: 3
^ : ->      1: 0
<- : ^      2: 1
v : <-      3: 2

"""
