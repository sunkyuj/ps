from queue import PriorityQueue
import sys

input = lambda: sys.stdin.readline().rstrip()
n, m, k, x = map(int, input().split())
g = {i: set() for i in range(1, n + 1)}
for _ in range(m):
    a, b = map(int, input().split())
    g[a].add(b)

dist = [300000 for _ in range(n + 1)]
dist[x] = 0
pq = PriorityQueue()
pq.put((0, x))
while not pq.empty():
    cost, cur = pq.get()
    if dist[cur] < cost:
        continue

    for nxt in g[cur]:
        if dist[nxt] > dist[cur] + 1:
            dist[nxt] = dist[cur] + 1
            pq.put((dist[nxt], nxt))

ans = []
for i in range(1, n + 1):
    if dist[i] == k:
        ans.append(i)
if ans:
    ans.sort()
    for a in ans:
        print(a)
else:
    print(-1)
