from heapq import heappop, heappush

MAX = 300000001
m, n, k = map(int, input().split())  # m edges, n vectors, k forbidden
# n<=3만, m<=30만, k<=50만
start, end = map(int, input().split())
conn = {i: {} for i in range(n)}
edges = {}
forbidden = set()
for _ in range(m):
    x, y, c = map(int, input().split())
    if (x, y) not in edges:
        conn[x][y] = c
        edges[(x, y)] = c
    else:
        conn[x][y] = min(conn[x][y], c)
        edges[(x, y)] = min(edges[(x, y)], c)

for _ in range(k):
    x, y, z = map(int, input().split())
    forbidden.add((x, y, z))

# if subpath in forbidden -> return -1
# 노드 여러번 방문 가능
# v->v 의 경로는 0
dist = [MAX for _ in range(n)]
dist[start] = 0
cnt = 0
hq = []  # (cost, start, prev)
heappush(hq, (0, start, -1))

visited = set()
# 어떻게 사이클을 시간안에 처리할 것인가?
while hq:
    cost, x, prev = heappop(hq)
    if x == end:
        print(cost)
        exit()
    for nx in conn[x]:
        ncost = conn[x][nx]
        if (prev, x, nx) in forbidden or (x, nx) in visited:
            continue
        heappush(hq, (cost + ncost, nx, x))
        visited.add((x, nx))
print(-1)
"""

3 4 1
0 3
0 1 1
1 2 1
2 0 1
9 9 9

3 4 1
0 3
0 1 0
1 0 0
1 3 7
9 9 9
"""
