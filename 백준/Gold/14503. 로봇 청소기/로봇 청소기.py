n, m = map(int, input().split())
r, c, d = map(int, input().split())  # 0 1 2 3 / 북 동 남 서
board = [list(map(int, input().split())) for _ in range(n)]


dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

clean = True
ans = 0

while 1:
    if clean:
        board[r][c] = 2  # 청소 완료
        ans += 1

    clean = False
    for i in range(1, 5):  # 네 방향 탐색
        ny, nx = r + dy[(d - i) % 4], c + dx[(d - i) % 4]
        if board[ny][nx] == 0:
            clean = True
            r, c, d = ny, nx, (d - i) % 4
            break  # 네 방향 중 청소할 곳 있음
    if clean:
        continue

    # 네 방향 중 청소할 곳 없음
    ny, nx = r + dy[(d - 2) % 4], c + dx[(d - 2) % 4]
    if board[ny][nx] != 1:  # 후진, 벽 아님
        r, c = ny, nx
    else:  # 벽이라 후진 못함
        break
print(ans)
