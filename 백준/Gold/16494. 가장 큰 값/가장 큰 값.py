N, M = map(int, input().split())
a = list(map(int, input().split()))


s = [0 for _ in range(N + 1)]
for i in range(N):
    s[i] = s[i - 1] + a[i]


ans = -2000


def f(g, end, gsum):
    if g == M:
        global ans
        ans = max(ans, gsum)
        return
    for ns in range(end + 1, N - (M - g - 1)):
        for ne in range(ns, N - (M - g - 1)):
            f(g + 1, ne, gsum + s[ne] - s[ns - 1])


for start in range(N - M + 1):
    for end in range(start, N - M + 1):
        f(1, end, s[end] - s[start - 1])
print(ans)
