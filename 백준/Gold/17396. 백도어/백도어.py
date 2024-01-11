from heapq import heappop, heappush
import sys

input = lambda: sys.stdin.readline().rstrip()

MAX = 10**13
n, m = map(int, input().split())  # 10만, 30만
visible = list(map(int, input().split()))
conn = {i: {} for i in range(n)}
for _ in range(m):
    a, b, t = map(int, input().split())
    conn[a][b] = t
    conn[b][a] = t

hq = [(0, 0)]
dist = [MAX for _ in range(n)]
dist[0] = 0

while hq:
    cost, cur = heappop(hq)
    if cost > dist[cur]:
        continue
    if cur == n - 1:
        print(cost)
        exit()

    for nxt, ncost in conn[cur].items():
        if visible[nxt] and nxt != n - 1:
            continue

        if dist[nxt] > cost + ncost:
            dist[nxt] = cost + ncost
            heappush(hq, (dist[nxt], nxt))

print(-1)
