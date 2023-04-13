import heapq
import sys

input = lambda: sys.stdin.readline().rstrip()
MAX = 1000 * 100000 + 1

for tc in range(int(input())):
    n, d, c = map(int, input().split())
    # a가 b에 의존 = b감염되면 a도 감염
    conn = {i: {} for i in range(1, n + 1)}
    for i in range(d):
        a, b, s = map(int, input().split())
        conn[b][a] = s

    dist = [MAX] * (n + 1)
    dist[c] = 0
    hq = []
    heapq.heappush(hq, (0, c))  # cost,x
    time = 0

    while hq:
        cost, cur = heapq.heappop(hq)
        if dist[cur] < cost:
            continue
        time = dist[cur]
        for nxt, ncost in conn[cur].items():
            if dist[nxt] > dist[cur] + ncost:
                dist[nxt] = dist[cur] + ncost
                heapq.heappush(hq, (dist[nxt], nxt))

    print(len(dist) - dist.count(MAX), time)