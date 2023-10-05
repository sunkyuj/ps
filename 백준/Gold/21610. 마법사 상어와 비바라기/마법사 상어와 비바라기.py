n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

dy = [0, -1, -1, -1, 0, 1, 1, 1]
dx = [-1, -1, 0, 1, 1, 1, 0, -1]  # 1부터 시작
in_range = lambda y, x: 0 <= y < n and 0 <= x < n  # 복사시에만 사용 (구름 이동시엔 모듈로 연산)

clouds = {(n - 1, 0), (n - 1, 1), (n - 2, 0), (n - 2, 1)}

for _ in range(m):  # 100
    d, s = map(int, input().split())
    increased = set()
    for cloud in clouds:
        cloud = ((cloud[0] + dy[d - 1] * s) % n, (cloud[1] + dx[d - 1] * s) % n)
        y, x = cloud
        board[y][x] += 1
        increased.add((y, x))

    for y, x in increased:
        cnt = 0
        for k in range(1, 8, 2):  # 1 3 5 7
            ny = y + dy[k]
            nx = x + dx[k]
            if in_range(ny, nx) and board[ny][nx]:
                # 물이 있는 바구니의 수만큼 물의 양 증가
                cnt += 1
        board[y][x] += cnt

    new_cloudes = set()
    for y in range(n):  # 2500
        for x in range(n):
            if (y, x) not in increased and board[y][x] >= 2:
                board[y][x] -= 2
                new_cloudes.add((y, x))
    clouds = new_cloudes


ans = 0
for y in range(n):
    for x in range(n):
        ans += board[y][x]
print(ans)
