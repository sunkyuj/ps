import sys

sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m


def find(v):
    if v == root[v]:
        return v
    root[v] = find(root[v])
    return root[v]


def union(v1, v2):  # union v1 to v2 (v1 -> v2)
    r1 = find(v1)
    r2 = find(v2)
    root[r1] = r2


def ub(key):
    s, e = 0, m - 1
    while s <= e:
        mid = (s + e) // 2
        if my[mid] <= key:
            s = mid + 1
        else:
            e = mid - 1
    return s  # return idx


n, m, k = map(int, input().split())

my = list(map(int, input().split()))
root = [i for i in range(m + 1)]
enemy = list(map(int, input().split()))

my.sort()

for num in enemy:
    idx = ub(num)
    choice_idx = find(idx)
    print(my[choice_idx])
    union(choice_idx, choice_idx + 1)
