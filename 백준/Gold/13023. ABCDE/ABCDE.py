n, m = map(int, input().split())
rel = {i: set() for i in range(n)}
for i in range(m):
    a, b = map(int, input().split())
    rel[a].add(b)
    rel[b].add(a)


def f(idx, cnt):
    if cnt >= 5:
        print(1)
        exit()

    visit[idx] = 1
    for friend in rel[idx]:
        if not visit[friend]:
            f(friend, cnt + 1)
    visit[idx] = 0


visit = [0] * n
for i in range(n):
    f(i, 1)

print(0)
