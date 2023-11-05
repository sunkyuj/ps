import sys

sys.setrecursionlimit(10**6)
n = int(input())
arr = list(map(int, input().split()))
visit = [0] * (n + 1)
ans = []


def f(idx):
    global ans
    if idx == n:
        return

    x = arr[idx]
    visit[x] = 1
    f(idx + 1)
    visit[x] = 0

    first_small_num = n
    for i in range(x - 1, 0, -1):
        if not visit[i]:
            first_small_num = i
            visit[i] = 1
            break
    if first_small_num != n:
        new = arr[:idx] + [first_small_num]
        for i in range(n, 0, -1):
            if not visit[i]:
                new.append(i)
        visit[first_small_num] = 0
        for x in new:
            print(x, end=" ")
        exit()
    return


f(0)
print(-1)

"""
5 4 3 2 1
4 3 2 1 -

"""
