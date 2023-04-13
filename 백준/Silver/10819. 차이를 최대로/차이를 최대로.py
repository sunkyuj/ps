n = int(input())
arr = list(map(int, input().split()))

ans = -9999999


def f(result, remain):
    if remain == []:
        global ans
        s = 0
        for i in range(n - 1):
            s += abs(result[i] - result[i + 1])
        ans = max(ans, s)
        return

    for i in range(len(remain)):
        f(result + [remain[i]], remain[:i] + remain[i + 1 :])


f([], arr)

print(ans)
