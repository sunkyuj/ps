import sys
import bisect

input = lambda: sys.stdin.readline().rstrip()

squares = [i**2 for i in range(46342)]  # 0 1 4 9 16 ...

for _ in range(int(input())):
    x, y = map(int, input().split())  # y 최대 2**31 = 2147483648 (21억)
    x, y = 0, y - x

    idx = bisect.bisect_left(squares, y)
    a, b = idx - 1, idx

    m = (a**2 + 1 + b**2) // 2
    if y >= m:
        print(2 * b - 1)
    else:
        print(2 * a)
