import sys

input = lambda: sys.stdin.readline().rstrip()

n, m, k = map(int, input().split())
arr = [int(input()) for _ in range(n)]
seg = [0] * (4 * n)


def init(idx, start, end):
    if start == end:  # leaf
        seg[idx] = arr[start]
        return seg[idx]

    mid = (start + end) // 2
    seg[idx] = init(idx * 2, start, mid) + init(idx * 2 + 1, mid + 1, end)
    return seg[idx]


def get(idx, start, end, left, right):
    if end < left or right < start:  # 범위 벗어남
        return 0

    if left <= start and end <= right:  # 범위 안에 있음
        return seg[idx]

    mid = (start + end) // 2
    l = get(idx * 2, start, mid, left, right)
    r = get(idx * 2 + 1, mid + 1, end, left, right)
    return l + r


def update(idx, start, end, change_idx):
    if change_idx < start or end < change_idx:
        return

    seg[idx] += diff
    if start == end:
        return

    mid = (start + end) // 2
    update(idx * 2, start, mid, change_idx)
    update(idx * 2 + 1, mid + 1, end, change_idx)


init(1, 0, n - 1)

for i in range(m + k):
    a, b, c = map(int, input().split())
    if a == 1:
        diff = c - arr[b - 1]
        arr[b - 1] = c
        update(1, 0, n - 1, b - 1)  # arr[b-1] = c
    else:
        print(get(1, 0, n - 1, b - 1, c - 1))  # b~c sum
