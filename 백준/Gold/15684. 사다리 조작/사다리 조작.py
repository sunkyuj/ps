from itertools import combinations

n, m, h = map(int, input().split())

ans = -1  # 추가해야하는 가로선 개수의 최소값

# i번 세로선의 결과가 i번이 나와야 함
conn = [[0] * (h + 1) for _ in range(n + 1)]  # conn[x][y][0 or 1]: x번 세로줄에 y 가로줄 위치의 좌 우 연결
# -1: left, 0: mid, 1: right
for i in range(m):
    a, b = map(int, input().split())
    conn[b][a] = 1
    conn[b + 1][a] = -1


def check():
    for i in range(1, n + 1):
        cur = i
        for j in range(1, h + 1):
            if conn[cur][j] == -1:  # left
                cur -= 1
            elif conn[cur][j] == 1:  # right
                cur += 1
        if cur != i:
            return 0
    return 1


def f():
    if check():
        return 0

    all_edges = []
    for i in range(1, n):
        for j in range(1, h + 1):
            all_edges.append((i, j))

    c1 = combinations(all_edges, 1)
    for cs in c1:
        for c in cs:
            x, y = c
            if conn[x][y] == 0 and conn[x + 1][y] == 0:
                conn[x][y] = 1
                conn[x + 1][y] = -1
                if check():
                    return 1
                conn[x][y] = 0
                conn[x + 1][y] = 0

    c2 = combinations(all_edges, 2)
    for cs in c2:
        changed = []
        for c in cs:
            x, y = c
            if conn[x][y] == 0 and conn[x + 1][y] == 0:
                conn[x][y] = 1
                conn[x + 1][y] = -1
                changed.append((x, y))
        if len(changed) == 2 and check():
            return 2
        for x, y in changed:
            conn[x][y] = 0
            conn[x + 1][y] = 0

    c3 = combinations(all_edges, 3)
    for cs in c3:
        changed = []
        for c in cs:
            x, y = c
            if conn[x][y] == 0 and conn[x + 1][y] == 0:
                conn[x][y] = 1
                conn[x + 1][y] = -1
                changed.append((x, y))
        if len(changed) == 3 and check():
            return 3
        for x, y in changed:
            conn[x][y] = 0
            conn[x + 1][y] = 0

    return -1


ans = f()
print(ans)