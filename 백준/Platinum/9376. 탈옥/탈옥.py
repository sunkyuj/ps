from collections import deque

MAX = 10001
in_range = lambda y, x: 0 <= y < h and 0 <= x < w

for _ in range(int(input())):
    h, w = map(int, input().split())
    board = [["."] + list(input()) + ["."] for _ in range(h)]  # 열 패딩
    board.insert(0, ["." for _ in range(w + 2)])
    board.append(["." for _ in range(w + 2)])
    h += 2
    w += 2  # 패딩된 크기 조정
    tars = [(0, 0)]
    for i in range(h):
        for j in range(w):
            if board[i][j] == "$":
                board[i][j] = "."
                tars.append((i, j))

    dist = [
        [[MAX for _ in range(w)] for _ in range(h)],  # 상근
        [[MAX for _ in range(w)] for _ in range(h)],  # 죄수1
        [[MAX for _ in range(w)] for _ in range(h)],  # 죄수2
    ]
    ans_board = [[0 for _ in range(w)] for _ in range(h)]

    for k in range(3):
        sy, sx = tars[k]
        q = deque()
        q.append((sy, sx, 0))
        dist[k][sy][sx] = 0

        while q:
            y, x, d = q.popleft()
            if d > dist[k][y][x]:
                continue

            for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                ny, nx = y + dy, x + dx
                if not in_range(ny, nx) or board[ny][nx] == "*":
                    continue
                if board[ny][nx] == "." and dist[k][ny][nx] > d:
                    q.appendleft((ny, nx, d))
                    dist[k][ny][nx] = d

                if board[ny][nx] == "#" and dist[k][ny][nx] > d + 1:
                    q.append((ny, nx, d + 1))
                    dist[k][ny][nx] = d + 1

    answer = MAX
    for i in range(h):
        for j in range(w):
            for k in range(3):
                ans_board[i][j] += dist[k][i][j]
            if board[i][j] == "#":
                ans_board[i][j] -= 2
            answer = min(answer, ans_board[i][j])
    print(answer)
