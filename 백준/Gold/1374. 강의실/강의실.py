import sys
import heapq

input = lambda: sys.stdin.readline().rstrip()

n = int(input())

classes = [tuple(map(int, input().split()))[1:] for _ in range(n)]
classes.sort()
# print(classes)

ans = 1
hq = []  # (e,s)
heapq.heappush(hq, (classes[0][1], classes[0][0]))

for s, e in classes[1:]:  # 10만
    # 강의 안 겹치니까 시간 다 된 강의 빼줌
    while hq and hq[0][0] <= s:  #
        heapq.heappop(hq)  # 20
    if not hq or hq[0][0] > s:  # 강의 없거나, 강의 겹침
        heapq.heappush(hq, (e, s))  # 20
    ans = max(ans, len(hq))

print(ans)