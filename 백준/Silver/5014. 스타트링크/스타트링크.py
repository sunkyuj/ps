from collections import deque

MAX = 1000001

f, s, g, u, d = map(int, input().split())
q = deque()
visit = [MAX] * (f + 1)
q.append(s)
visit[s] = 0
while q:
    x = q.popleft()
    if x + u <= f and visit[x + u] > visit[x] + 1:
        q.append(x + u)
        visit[x + u] = visit[x] + 1
    if x - d >= 1 and visit[x - d] > visit[x] + 1:
        q.append(x - d)
        visit[x - d] = visit[x] + 1
if visit[g] != MAX:
    print(visit[g])
else:
    print("use the stairs")
