n, m, k = map(int, input().split())
ball_loc = set()  # 2500
board = [[set() for _ in range(n)] for _ in range(n)]
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, 1, 1, 1, 0, -1, -1, -1]

for _ in range(m):
    r, c, m, s, d = map(int, input().split())
    board[r - 1][c - 1].add((m, s, d))
    ball_loc.add((r - 1, c - 1))


for _ in range(k):  # 1000
    # 1. 파이어볼 이동
    new_loc = set()
    new_set = set()
    for y, x in ball_loc:
        for m, s, d in board[y][x]:  # 해당 칸 (y,x)에 있는 모든 파볼에 대해 이동
            ny, nx = (y + dy[d] * s) % n, (x + dx[d] * s) % n
            new_set.add((ny, nx, m, s, d))
            new_loc.add((ny, nx))
        board[y][x].clear()

    ball_loc = new_loc

    for ny, nx, m, s, d in new_set:
        board[ny][nx].add((m, s, d))

    rm_loc = set()
    # 2. 모두 이동 후, 2개 이상인 곳에서는...
    for y, x in ball_loc:
        #   1) 한 파볼로 합치기
        balls = board[y][x]
        if len(balls) >= 2:
            msum, ssum, ds = 0, 0, []
            for m, s, d in balls:
                msum += m
                ssum += s
                ds.append(d % 2)

            board[y][x] = set()
            #   2) 4개의 파볼로 나눠짐 (질량은 합/5, 속력은 합/개수, 방향 다 같으면 0,2,4,6 아니면 1,3,5,7)
            divm = msum // 5
            #   3) 질량 0인 파볼은 사라짐
            if divm == 0:
                rm_loc.add((y, x))
                continue

            divs = ssum // len(balls)
            new_dirs = [0, 2, 4, 6] if (sum(ds) in (0, len(ds))) else [1, 3, 5, 7]
            for new_dir in new_dirs:
                board[y][x].add((divm, divs, new_dir))
    ball_loc -= rm_loc


ans = 0
for y, x in ball_loc:
    balls = board[y][x]
    for m, s, d in balls:
        ans += m

print(ans)
