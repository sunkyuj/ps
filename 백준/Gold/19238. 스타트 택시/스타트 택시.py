from collections import deque

n, m, fuel = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
y, x = map(int, input().split())
y -= 1
x -= 1
dest = {}
for _ in range(m):
    cy, cx, gy, gx = map(int, input().split())
    cy -= 1
    cx -= 1
    gy -= 1
    gx -= 1
    dest[(cy, cx)] = (gy, gx)  # 손님위치 : 목적지

in_range = lambda y, x: 0 <= y < n and 0 <= x < n

# 최단거리 찾기
def bfs(y, x):
    min_l = 99999
    cand = []
    visit = [[0 for _ in range(n)] for _ in range(n)]
    visit[y][x] = 1
    q = deque()
    q.append((0, y, x))

    while q:
        l, y, x = q.popleft()
        if min_l < l:
            break
        if (y, x) in dest:
            min_l = l
            cand.append((l, y, x))

        for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            ny, nx = y + dy, x + dx
            if in_range(ny, nx) and not visit[ny][nx] and board[ny][nx] == 0:
                q.append((l + 1, ny, nx))
                visit[ny][nx] = 1
    # 실패
    if cand == []:
        print(-1)
        exit()

    return sorted(cand)[0]


def get_goal(y, x):
    gy, gx = dest[(y, x)]
    visit = [[0 for _ in range(n)] for _ in range(n)]
    visit[y][x] = 1
    q = deque()
    q.append((0, y, x))
    while q:
        l, y, x = q.popleft()
        if (y, x) == (gy, gx):
            return l

        for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            ny, nx = y + dy, x + dx
            if in_range(ny, nx) and not visit[ny][nx] and board[ny][nx] == 0:
                q.append((l + 1, ny, nx))
                visit[ny][nx] = 1
    # 실패
    print(-1)
    exit()


for _ in range(m):
    # 승객 위치 확정
    l, cy, cx = bfs(y, x)
    # 승객한테 이동
    fuel -= l
    # 목적지로 이동
    l_goal = get_goal(cy, cx)
    fuel -= l_goal
    y, x = dest[(cy, cx)]
    dest.pop((cy, cx))

    # 목적지 이동 성공시 소모한 연료의 두배가 충전됨
    if fuel < 0:
        print(-1)
        exit()
    else:
        # 소모 연료의 2배만큼 증가
        fuel += 2 * l_goal

print(fuel)
