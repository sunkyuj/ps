n, d = map(int, input().split())

g = {}
for _ in range(n):
    a, b, c = map(int, input().split())
    if a > d or b > d:
        continue
    g.setdefault(a, set())
    g[a].add((b, c))

dist = [i for i in range(d + 1)]
for i in range(d + 1):
    if i in g:
        for nx, ncost in g[i]:
            dist[nx] = min(dist[nx], dist[i] + ncost)
    if i < d:
        dist[i + 1] = min(dist[i] + 1, dist[i + 1])


print(dist[d])
