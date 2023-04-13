n = int(input())
w = [list(map(int, input().split())) for _ in range(n)]

ans = 999999999


def f(start, cur, cnt, cost_sum):
    if cnt == n:
        if w[cur][start]:
            global ans
            ans = min(ans, cost_sum + w[cur][start])
        return

    visit[cur] = 1
    for i in range(n):
        if w[cur][i] and not visit[i]:
            f(start, i, cnt + 1, cost_sum + w[cur][i])

    visit[cur] = 0
    return


visit = [0] * n
for i in range(n):
    f(i, i, 1, 0)

print(ans)
