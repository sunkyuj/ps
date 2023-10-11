n, k = map(int, input().split())
color = [list(map(int, input().split())) for _ in range(n)]
board = [[[] for _ in range(n)] for _ in range(n)]
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]
in_range = lambda y, x: 0 <= y < n and 0 <= x < n


def op_dir(dir):
    if dir == 0 or dir == 2:
        return dir + 1
    if dir == 1 or dir == 3:
        return dir - 1


chesses = []
for i in range(k):
    y, x, dir = map(int, input().split())
    y, x, dir = y - 1, x - 1, dir - 1
    chesses.append([y, x, dir])
    board[y][x].append(i)


for turn in range(1000):
    for i in range(k):
        # i번말 정보
        y, x, dir = chesses[i]
        ny, nx = y + dy[dir], x + dx[dir]
        if not in_range(ny, nx) or color[ny][nx] == 2:  # blue
            dir = op_dir(dir)
            chesses[i][2] = dir  # 방향 반대로 설정
            ny, nx = y + dy[dir], x + dx[dir]  # 다음 행선지 갱신 (반대쪽으로)
            if not in_range(ny, nx) or color[ny][nx] == 2:  # 또 파랑임
                continue

        # i번말의 스택위치
        idx = board[y][x].index(i)
        # i번말부터 위에 있는 말들 떼어내기
        sub = board[y][x][idx:]
        board[y][x] = board[y][x][:idx]

        if in_range(ny, nx):
            if color[ny][nx] == 0:  # white
                # i번 말 위에 있는거 그대로 옮기기
                board[ny][nx] += sub
            elif color[ny][nx] == 1:  # red
                # i번 말 위에 있는거 거꾸로 옮기기
                board[ny][nx] += sub[::-1]

            for j in sub:  # 이동한 말 정보 갱신
                chesses[j][0] = ny
                chesses[j][1] = nx

        if len(board[ny][nx]) >= 4:
            print(turn + 1)
            exit()

print(-1)
