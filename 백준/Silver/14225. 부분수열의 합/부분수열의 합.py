n = int(input())
arr = list(map(int, input().split()))
arr.sort()
visit = [0] * (sum(arr) + 1)
stack = []

# 1 2 5
# 1 2 4


def f(idx, s):
    visit[s] = 1
    if idx == n:
        return
    f(idx + 1, s)
    f(idx + 1, s + arr[idx])
    return


f(0, 0)
i = 1
while i < len(visit) and visit[i] != 0:
    i += 1
print(i)
