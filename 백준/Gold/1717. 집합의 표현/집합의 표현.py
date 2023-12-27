import sys

sys.setrecursionlimit(10**7)
input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
r = [i for i in range(n + 1)]


def find(v):
    if r[v] == v:
        return v
    r[v] = find(r[v])
    return r[v]


def union(v1, v2):
    r1 = find(v1)
    r2 = find(v2)

    if r1 > r2:
        r1, r2 = r2, r1
    r[r2] = r1


for _ in range(m):
    op, a, b = map(int, input().split())
    if op == 0:
        union(a, b)
    else:
        ra = find(a)
        rb = find(b)
        if ra == rb:
            print("YES")
        else:
            print("NO")
