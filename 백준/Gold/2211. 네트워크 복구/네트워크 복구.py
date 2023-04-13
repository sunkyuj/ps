import sys
import heapq

input = lambda: sys.stdin.readline().rstrip()
MAX = 1000 * 10 + 1
n, m = map(int, input().split())
conn = {i: {} for i in range(1, n + 1)}
for i in range(m):
    a, b, c = map(int, input().split())
    conn[a][b] = c
    conn[b][a] = c

ans_edges = []
dist = [MAX] * (n + 1)
dist[1] = 0
hq = []
heapq.heappush(hq, (0, 1, 0))  # cost, x,prev
while hq:
    cost, x, prev = heapq.heappop(hq)
    if dist[x] < cost:
        continue
    ans_edges.append((prev, x))
    for nxt, ncost in conn[x].items():
        if dist[nxt] > dist[x] + ncost:
            dist[nxt] = dist[x] + ncost
            heapq.heappush(hq, (dist[nxt], nxt, x))

print(len(ans_edges) - 1)
for a, b in ans_edges[1:]:
    print(a, b)