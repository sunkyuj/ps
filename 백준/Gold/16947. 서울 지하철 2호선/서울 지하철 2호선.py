import sys

sys.setrecursionlimit(10**7)
from collections import deque

n = int(input())
conn = {i: set() for i in range(1, n + 1)}
for _ in range(n):
    a, b = map(int, input().split())
    conn[a].add(b)
    conn[b].add(a)
visit = [0] * (n + 1)
cycle = set()


def dfs(v, prev):
    visit[v] = 1

    for x in conn[v]:
        if x == prev:
            continue
        if visit[x]:  # cycle
            cycle.add(x)  # root
            cycle.add(v)
            return 1
        if dfs(x, v):
            if v in cycle:
                return 0
            cycle.add(v)
            return 1


dfs(1, 0)
answer = [0] * (n + 1)

for i in range(1, n + 1):
    if i in cycle:
        continue

    q = deque()
    q.append((i, 0, 0))
    while q:
        v, prev, l = q.popleft()
        if v in cycle:
            answer[i] = l
            break
        for x in conn[v]:
            if x == prev:
                continue
            q.append((x, v, l + 1))

for ans in answer[1:]:
    print(ans, end=" ")
"""
    4-6
    |    
1-2-3-5
\__/
"""
