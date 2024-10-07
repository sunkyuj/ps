import sys

sys.setrecursionlimit(6000)
input = lambda: sys.stdin.readline().rstrip()

dydx = [(-1, 0), (0, -1), (1, 0), (0, 1)]

r1, c1, r2, c2 = map(int, input().split())

h, w = r2 - r1 + 1, c2 - c1 + 1
board = [[0 for _ in range(min(5, w))] for _ in range(h)]
num = 1
total = len(board) * len(board[0])


if r1 <= 0 <= r2 and c1 <= 0 <= c2:
    board[0 - r1][0 - c1] = num
    total -= 1
num += 1
y, x = 1, 1
for move in range(2, 10001, 2):
    if total == 0:
        break
    for dy, dx in dydx:
        for _ in range(move):
            y, x = y + dy, x + dx
            if r1 <= y <= r2 and c1 <= x <= c2:
                board[y - r1][x - c1] = num
                total -= 1
            num += 1
    y += 1
    x += 1


space = max(
    [
        len(str(board[0][0])),
        len(str(board[0][-1])),
        len(str(board[-1][0])),
        len(str(board[-1][-1])),
    ]
)

for row in board:
    for j in range(len(row)):
        print(" " * (space - len(str(row[j]))), end="")
        print(row[j], end=" ")
    print()
