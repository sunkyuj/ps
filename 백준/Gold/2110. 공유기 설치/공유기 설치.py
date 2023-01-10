import sys

input = lambda: sys.stdin.readline().rstrip()
n, c = map(int, input().split())
x = [int(input()) for _ in range(n)]
x.sort()

_min, _max = 1, x[-1]
ans = 0


while _min <= _max:
    mid = (_min + _max) // 2

    # 처음에 공유기 무조건 설치
    cnt = 1
    cur = x[0]

    for i in range(n):
        if x[i] >= cur + mid:
            cur = x[i]
            cnt += 1

    if cnt < c:
        _max = mid - 1
    else:
        _min = mid + 1
        ans = mid

print(ans)

# 1 2 4 8 9
"""
7 4
1       
3 
6
10
15
21
22

"""
