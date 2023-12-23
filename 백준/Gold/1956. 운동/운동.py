MAX = 400 * 10000 + 1
v, e = map(int, input().split())
conn = {i: {} for i in range(1, v + 1)}
dist = [[MAX] * (v + 1) for _ in range(v + 1)]
for _ in range(e):
    a, b, c = map(int, input().split())
    conn[a][b] = c
    dist[a][b] = c

for i in range(1, v + 1):  # 400
    for j in range(1, v + 1):  # 16만
        for k in range(1, v + 1):  # 6400만
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
ans = MAX
for i in range(1, v + 1):
    ans = min(ans, dist[i][i])
if ans == MAX:
    print(-1)
else:
    print(ans)
