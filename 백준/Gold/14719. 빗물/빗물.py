ans = 0
h, w = map(int, input().split())
land = list(map(int, input().split()))

board = [[0 for _ in range(w)] for _ in range(h)]

j = 0
for l in land:
    i = h - 1
    for _ in range(l):
        board[i][j] = 1
        i -= 1
    j += 1

for i in range(h - 1, -1, -1):
    wall = 0
    water = 0
    for j in range(w):
        if board[i][j] == 1:  # wall
            if not wall:  # first wall
                wall = 1
            else:  # second wall
                ans += water
            water = 0
        else:  # water
            water += 1
print(ans)
