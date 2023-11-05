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

    first_big_num = 0
    for i in range(x + 1, n + 1):
        if not visit[i]:
            first_big_num = i
            visit[i] = 1
            break
    if first_big_num != 0:
        new = arr[:idx] + [first_big_num]
        for i in range(1, n + 1):
            if not visit[i]:
                new.append(i)
        visit[first_big_num] = 0
        for x in new:
            print(x, end=" ")
        exit()
    return


f(0)
print(-1)