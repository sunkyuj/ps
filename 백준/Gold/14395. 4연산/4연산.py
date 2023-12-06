from collections import deque

MAX = 1000000001
s, t = map(int, input().split())  # 10억
inc = lambda a, b: t < a <= b
if s == t:
    print(0)
    exit()

q = deque()
visit = {}

q.append((s, ""))
visit[s] = 0  # 낮은게 좋음

ans_len = MAX
ans = "//"

while q:
    x, ops = q.popleft()
    cnt = len(ops)
    if ans_len < cnt:
        continue

    if x == t:
        ans_len = cnt
        ans = min(ans, ops)
        continue

    xx = x * x
    if not inc(x, xx) and (xx not in visit or visit[xx] > cnt + 1):
        q.append((xx, ops + "*"))
        visit[xx] = cnt + 1
    x2 = x + x
    if not inc(x, x2) and (x2 not in visit or visit[x2] > cnt + 1):
        q.append((x * 2, ops + "+"))
        visit[x2] = cnt + 1
    if 0 not in visit or visit[0] > cnt + 1:
        q.append((0, ops + "-"))
        visit[0] = cnt + 1
    if x and (1 not in visit or visit[0] > cnt + 1):
        q.append((1, ops + "/"))
        visit[1] = cnt + 1

if ans_len == MAX:
    print(-1)
else:
    print(ans)
