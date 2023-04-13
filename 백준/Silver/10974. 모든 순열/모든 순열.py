n = int(input())
arr = list(range(1, n + 1))


def f(li, remain):
    if not remain:
        for x in li:
            print(x, end=" ")
        print()
        return
    for i in range(len(remain)):
        f(li + [remain[i]], remain[:i] + remain[i + 1 :])


f([], arr)
