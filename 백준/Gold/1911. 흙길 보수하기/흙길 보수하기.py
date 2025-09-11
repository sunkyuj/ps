import sys
import math

input = lambda: sys.stdin.readline().rstrip()

N, L = map(int, input().split())  # 10000, 100만

# 웅덩이 좌표 0~10억
holes = [tuple(map(int, input().split())) for _ in range(N)]  # i~j (j 미포함)
holes.sort()


ans = 0
pad_end = -1
for s, e in holes:
    if pad_end >= e - 1:  # 전 녀석이 현 녀석 아예 초과해버림
        continue
    if pad_end >= s:  # 전 녀석이 현 녀석 일부 침범
        s = pad_end + 1
    hole_l = e - s
    pads = math.ceil(hole_l / L)
    pad_end = s + L * pads - 1

    ans += pads

print(ans)
