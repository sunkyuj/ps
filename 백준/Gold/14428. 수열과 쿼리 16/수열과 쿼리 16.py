import sys

input = lambda: sys.stdin.readline().rstrip()
MAX = 10**9 + 1


def init(idx, start, end):

    if start == end:
        seg[idx] = (arr[start], start)  # min, idx
        return seg[idx]

    mid = (start + end) // 2
    seg[idx] = min(init(idx * 2, start, mid), init(idx * 2 + 1, mid + 1, end))
    return seg[idx]


def get(idx, start, end, left, right):  # -> (min, idx)
    if end < left or right < start:
        return (MAX, n)

    if left <= start and end <= right:
        return seg[idx]

    mid = (start + end) // 2
    return min(get(idx * 2, start, mid, left, right), get(idx * 2 + 1, mid + 1, end, left, right))


def update(idx, start, end):  # update 할 때 , 옆자식도 가져와서 비교 후 넣어주기

    if start == end:
        seg[idx] = (val, target)
        return seg[idx]

    mid = (start + end) // 2
    if target <= mid:
        a = update(idx * 2, start, mid)
        b = seg[idx * 2 + 1]
    else:
        a = seg[idx * 2]
        b = update(idx * 2 + 1, mid + 1, end)

    seg[idx] = min(a, b)
    return seg[idx]


n = int(input())
arr = list(map(int, input().split()))
m = int(input())

seg = [(MAX, n) for _ in range(n * 4)]  # min, idx
init(1, 0, n - 1)

for q in range(m):
    a, b, c = map(int, input().split())
    if a == 1:
        arr[b - 1] = c
        target, val = b - 1, c
        update(1, 0, n - 1)
    else:
        print(get(1, 0, n - 1, b - 1, c - 1)[1] + 1)
    # print(arr)
    # print(seg)

"""
5 4 3 2 1

2 1 3 -> 3
2 1 4 -> 4
1 5 3 == 5 4 3 2 3
2 3 5 -> 4
1 4 3 == 5 4 3 3 3
2 3 5 -> 3

"""
