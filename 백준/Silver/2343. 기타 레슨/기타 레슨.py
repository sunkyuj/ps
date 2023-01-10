n, m = map(int, input().split())
arr = list(map(int, input().split()))
_min, _max = 1, sum(arr)

ans = 100000 * 10000

while _min <= _max:
    mid = (_min + _max) // 2
    s = 0
    cnt = 1
    bmax = 0
    for i in range(n):
        if s + arr[i] <= mid:
            s += arr[i]
        else:
            cnt += 1
            s = arr[i]

        bmax = max(bmax, s)

    if cnt <= m:
        ans = min(ans, bmax)
        _max = mid - 1
    else:
        _min = mid + 1

print(ans)
