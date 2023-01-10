import sys
from queue import PriorityQueue

#sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
in_range = lambda y, x: 0 <= y < h and 0 <= x < w

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]


def priority(c):
    if c == "$":  # goal
        return 0
    if "a" <= c <= "z":  # key
        return 1
    if c == ".":  # space
        return 3
    if "A" <= c <= "Z":  # door
        if c.lower() in keys:  # opened door
            return 2
        else:  # closed door
            return 4  # no key, can't open


for _ in range(int(input())):
    h, w = map(int, input().split())
    board = [list(input()) for _ in range(h)]
    keys = set(input())

    found_locked_door = {}
    for alp in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
        found_locked_door.setdefault(alp, set())

    visit = [[0 for _ in range(w)] for _ in range(h)]
    pq = PriorityQueue()

    ans = 0
    for i in range(h):
        for j in range(w):
            if (i == 0 or i == h - 1 or j == 0 or j == w - 1) and board[i][j] != "*":
                p = priority(board[i][j])
                if p == 4:  # no key, can't open
                    found_locked_door[board[i][j]].add((i, j))
                    continue
                pq.put((p, i, j))
                visit[i][j] = 1

    while not pq.empty():
        p, y, x = pq.get()

        if p == 0:  # goal
            ans += 1
        elif p == 1:  # key
            keys.add(board[y][x])
            if board[y][x].upper() in found_locked_door:  # now we can open!
                for door_y, door_x in found_locked_door[board[y][x].upper()]:
                    visit[door_y][door_x] = 1
                    pq.put((2, door_y, door_x))
        elif p == 2 or p == 3:
            pass
        elif p == 4:
            if board[y][x].lower() in keys:
                pass
            else:
                break

        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if in_range(ny, nx) and not visit[ny][nx] and board[ny][nx] != "*":
                np = priority(board[ny][nx])
                if np == 4:  # no key, can't open
                    found_locked_door[board[ny][nx]].add((ny, nx))
                    continue
                visit[ny][nx] = 1
                pq.put((np, ny, nx))

    print(ans)
