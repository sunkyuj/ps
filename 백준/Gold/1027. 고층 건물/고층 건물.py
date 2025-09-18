n = int(input())  # 50
y = list(map(int, input().split()))

ang = [[0 for _ in range(n)] for _ in range(n)]
cnt = [0] * n
fx = [[0 for _ in range(n)] for _ in range(n)]


def make_line_fx(a, b):
    dy, dx = y[b] - y[a], b - a
    diff = dy / dx
    x = 0
    return lambda x: diff * (x - a) + y[a]


for i in range(n):
    for j in range(n):
        if i == j:
            continue
        fx[i][j] = make_line_fx(i, j)

for i in range(n):
    for j in range(i + 1, n):
        f = fx[i][j]
        can_see = True
        for k in range(i + 1, j):
            if f(k) <= y[k]:
                can_see = False
                break
        if can_see:
            cnt[i] += 1
            cnt[j] += 1
print(max(cnt))
