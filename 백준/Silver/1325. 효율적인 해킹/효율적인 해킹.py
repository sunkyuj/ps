import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
conn = {i: [] for i in range(1, n + 1)}

for i in range(m):
    a, b = map(int, input().split())
    conn[b].append(a)


def bfs(v):
    visit = [0] * (n + 1)
    q = deque()
    q.append(v)
    visit[v] = 1

    cnt = 0
    while q:
        x = q.popleft()
        cnt += 1
        for nxt in conn[x]:
            if not visit[nxt]:
                q.append(nxt)
                visit[nxt] = 1
    return cnt


ans = []
max_val = -1
for i in range(1, n + 1):  # 10000
    cnt = bfs(i)
    if cnt > max_val:
        max_val = cnt
        ans = []
        ans.append(i)
    elif cnt == max_val:
        ans.append(i)

for a in ans:
    print(a, end=" ")


"""
4 -> 3 -> 1
5 -/^ \-> 2

"""
