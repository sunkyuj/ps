from heapq import heappop, heappush

MAX = 100 * 100000 + 1
n, m = map(int, input().split())
conn = {i: {} for i in range(1, n + 1)}

for _ in range(m):
    a, b, c = map(int, input().split())
    conn[a][b] = c
    conn[b][a] = c
s, t = map(int, input().split())

dist = [MAX] * (n + 1)
hq = [(0, s)]
dist[s] = 0

while hq:
    cost, cur = heappop(hq)
    if cur == t:
        print(cost)
        exit()

    for nxt, ncost in conn[cur].items():
        if dist[nxt] > cost + ncost:
            dist[nxt] = cost + ncost
            heappush(hq, (dist[nxt], nxt))
