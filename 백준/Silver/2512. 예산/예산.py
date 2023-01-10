n = int(input())  # 10000
arr = list(map(int, input().split()))  # 1~100000
m = int(input())  # 10억
arr.sort()


def lower_bound(start, end, k):
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] > k:
            end = mid - 1
        elif arr[mid] <= k:
            start = mid + 1

    return end


min_val, max_val = 1, arr[-1]

while min_val <= max_val:
    mid = (min_val + max_val) // 2
    lb = lower_bound(0, n - 1, mid)
    s = sum(arr[: lb + 1]) + (n - 1 - lb) * mid

    if s <= m:
        min_val = mid + 1
    elif s > m:
        max_val = mid - 1

print(max_val)
