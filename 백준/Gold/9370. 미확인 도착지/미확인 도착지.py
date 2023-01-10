import sys
from queue import PriorityQueue

input = lambda: sys.stdin.readline().rstrip()
MAX = 100000000


def dij(start):
    dist = [MAX for _ in range(n + 1)]
    dist[start] = 0

    pq = PriorityQueue()
    pq.put((0, start))  # cost, x

    while not pq.empty():
        cost, x = pq.get()
        if cost > dist[x]:
            continue

        for to, ncost in edge[x].items():
            if dist[to] > cost + ncost:
                dist[to] = cost + ncost
                pq.put((dist[to], to))

    return dist


for _ in range(int(input())):
    n, m, t = map(int, input().split())
    edge = {i: {} for i in range(n + 1)}
    s, g, h = map(int, input().split())  # s= 예술가 출발지, g,h = 예술가가 지나간 도로
    for i in range(m):
        a, b, c = map(int, input().split())
        edge[a][b] = edge[b][a] = c
    candidate = [int(input()) for _ in range(t)]

    dist_s = dij(s)
    dist_g = dij(g)
    dist_h = dij(h)

    ans = []
    for c in candidate:

        sghc = dist_s[g] + dist_g[h] + dist_h[c]  # s - g - h - c
        shgc = dist_s[h] + dist_h[g] + dist_g[c]  # s - h - g - c
        if dist_s[c] == sghc or dist_s[c] == shgc:
            ans.append(c)

    ans.sort()
    for a in ans:
        print(a, end=" ")
    print()
"""
1
4 4 1
1 3 4
1 2 3
2 4 4
1 3 4
3 4 3
4
"""
