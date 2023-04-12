import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())  # 100,000
locations = [tuple(sorted(map(int, input().split()))) for _ in range(n)]
# (-1억~1억)
locations.sort()

d = int(input())  # 2억

start, end = [], []
for i, loc in enumerate(locations):
    start.append((loc[0], i))
    end.append((loc[1], i))
start.sort()
end.sort()

s = set()  # 커버 가능한 인덱스들이 들어감
startpoint = start[0][0]  # 5
endpoint = startpoint + d  # 35
jleft, jright = 0, 0
for j in range(n):
    if end[j][0] > endpoint:
        jright = j
        break
    s.add(end[j][1])

ans = len(s)
for i in range(1, n):
    if i - 1 in s:
        s.remove(i - 1)
    startpoint = start[i][0]
    if startpoint == start[i - 1][0]:  # 시작 위치 동일하면 패스
        continue

    endpoint = startpoint + d
    while end[jleft][1] < i:
        jleft += 1

    for j in range(jright, n):
        if end[j][0] > endpoint:
            jright = j
            break
        if end[j][1] >= i:
            s.add(end[j][1])
    ans = max(ans, len(s))

print(ans)


