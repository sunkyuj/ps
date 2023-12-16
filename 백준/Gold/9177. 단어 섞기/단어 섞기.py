import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

n = int(input())


def bfs(s1, s2, s3):
    q = deque()
    q.append((0, 0, 0))  # i1, i2, i3
    visit[0][0] = 1  # visit[i1][i2]

    while q:
        i1, i2, i3 = q.popleft()

        if i3 == len(s3):
            return 1
        if i1 < len(s1) and s1[i1] == s3[i3] and not visit[i1 + 1][i2]:
            q.append((i1 + 1, i2, i3 + 1))
            visit[i1 + 1][i2] = 1
        if i2 < len(s2) and s2[i2] == s3[i3] and not visit[i1][i2 + 1]:
            q.append((i1, i2 + 1, i3 + 1))
            visit[i1][i2 + 1] = 1

    return 0


for i in range(1, n + 1):  # 1000
    ans = ""
    s1, s2, s3 = input().split()  # 200 200 400
    visit = [[0] * (len(s2) + 1) for _ in range(len(s1) + 1)]
    if bfs(s1, s2, s3):
        print(f"Data set {i}: yes")
    else:
        print(f"Data set {i}: no")


"""
핵심: s1과 s2로 s3를 형성할 수 있는가?
cat cat xxxcat 은 안됨, 


"""
