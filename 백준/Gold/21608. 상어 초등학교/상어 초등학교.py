ans = 0
n = int(input())
in_range = lambda y, x: 0 <= y < n and 0 <= x < n

board = [[0 for _ in range(n)] for _ in range(n)]
like_info = [[] for _ in range(n * n + 1)]

for _ in range(n * n):  # 400
    info = list(map(int, input().split()))
    number = info[0]
    likes = info[1:]
    like_info[number] = likes

    candidates = []  # (like_n, empty_n, y,x), heapq?

    for y in range(n):  # 20
        for x in range(n):  # 20
            if board[y][x]:  # 이미 찬 자리면 패스
                continue

            like_n = 0
            empty_n = 0
            for dy, dx in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                ny, nx = y + dy, x + dx
                if not in_range(ny, nx):
                    continue
                if board[ny][nx] in likes:
                    like_n += 1
                if board[ny][nx] == 0:
                    empty_n += 1
            candidates.append((like_n, empty_n, -y, -x))

    candidates.sort(reverse=1)
    lk, em, y, x = candidates[0]
    board[-y][-x] = number

for y in range(n):
    for x in range(n):
        number = board[y][x]
        cnt = 0
        for dy, dx in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            ny, nx = y + dy, x + dx
            if not in_range(ny, nx):
                continue
            if board[ny][nx] in like_info[number]:
                cnt += 1

        if cnt:
            ans += 10 ** (cnt - 1)
print(ans)
