import sys
from collections import deque

# sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()
MAX = 1000000001


n, q = map(int, input().split())
conn = {}
for i in range(1, n + 1):
    conn.setdefault(i, {})
# conn = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

for i in range(n - 1):
    a, b, c = map(int, input().split())
    conn[a][b] = conn[b][a] = c


def bfs():
    cnt = 0
    visit = [0 for _ in range(n + 1)]
    visit[v] = 1
    q = deque()
    q.append((v, MAX))
    while q:
        cur, min_cost = q.popleft()
        for to, cost in conn[cur].items():
            if cost >= k and not visit[to]:
                visit[to] = 1
                q.append((to, min(min_cost, cost)))
                cnt += 1
                
        """for to in range(1, n + 1):
            if conn[cur][to] >= k and not visit[to]:
                visit[to] = 1
                q.append((to, min(min_cost, conn[cur][to])))
                cnt += 1"""

    return cnt


for i in range(q):
    k, v = map(int, input().split())
    print((bfs()))
