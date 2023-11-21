n = int(input())
w = list(map(int, input().split()))
visit = [0] * n
ans = 0


def f(cnt, s):
    global ans
    if cnt == n - 2:
        ans = max(ans, s)
        return

    for i in range(1, n - 1):
        if visit[i]:
            continue

        l, r = i - 1, i + 1
        while visit[l]:
            l -= 1
        while visit[r]:
            r += 1
        visit[i] = 1
        f(cnt + 1, s + w[l] * w[r])
        visit[i] = 0


f(0, 0)
print(ans)
