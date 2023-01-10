import math
import sys


sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m
GRADIENT_MAX = 10001


def find(v):
    if v == root[v]:
        return v
    root[v] = find(root[v])
    return root[v]


def union(v1, v2):
    r1 = find(v1)
    r2 = find(v2)
    if r1 > r2:
        r1, r2 = r2, r1  # r1<=r2 되게끔
    root[r2] = r1


"""def cross(line1, line2):
    if line1[0] == line1[2]:  # 기울기 무한일때
        if (line2[0] - line1[0]) * (line2[2] - line1[0]) <= 0:
            return 1
        else:
            return 0

    f = lambda x: line1_gradient * (x - line1[0]) + line1[1]

    if (line2[1] - f(line2[0])) * (line2[3] - f(line2[2])) <= 0:  # 겹침
        return 1
    else:  # 안겹침
        return 0"""


def cross(line1, line2):

    v = (line1[2] - line1[0], line1[3] - line1[1])
    u1 = (line2[0] - line1[0], line2[1] - line1[1])
    u2 = (line2[2] - line1[0], line2[3] - line1[1])

    t1 = v[0] * u1[1] - v[1] * u1[0]  # line1 과 (line2[0],line2[1])로 만든 삼각형 넓이
    t2 = v[0] * u2[1] - v[1] * u2[0]  # line1 과 (line2[2],line2[3])로 만든 삼각형 넓이

    if t1 * t2 <= 0:
        if t1 == 0 and t2 == 0:
            a = (line1[0], line1[1])
            b = (line1[2], line1[3])
            c = (line2[0], line2[1])
            d = (line2[2], line2[3])
            if a > b:
                a, b = b, a
            if c > d:
                c, d = d, c
            return a <= c <= b or a <= d <= b or c <= a <= d or c <= b <= d
        return 1
    else:
        return 0


n = int(input())
lines = [0 for _ in range(n)]
for i in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    lines[i] = (x1, y1, x2, y2)

root = [i for i in range(n)]


for i in range(n - 1):
    for j in range(i + 1, n):
        if cross(lines[i], lines[j]) and cross(lines[j], lines[i]):
            if find(i) != find(j):
                union(i, j)


# 한 직선이 하나 또는 여러 그룹에 걸치는 경우
# 한 직선이 어느 그룹에도 걸치지 않는 경우

for i in range(n):
    find(i)

print(len(set(root)))

root.sort()
cnt = 1
max_cnt = 1
for i in range(1, n):
    cnt = cnt + 1 if root[i - 1] == root[i] else 1
    max_cnt = max(max_cnt, cnt)
print(max_cnt)
"""

9
1 11 80 93
46 19 7 53
72 83 99 51
84 97 42 98
73 63 94 22
44 73 79 40
58 86 13 97
34 53 30 16
34 72 3 81
---------------------
6
4

====================

12
1 1 -1 1
-1 1 -1 -1
-1 -1 1 -1
1 -1 1 1
0 2 2 0
2 0 0 2
-2 0 0 -2
0 2 -2 0
0 1 1 0
-1 0 0 -1
-1 0 0 1
1 0 0 -1
---------------
1
12

"""
