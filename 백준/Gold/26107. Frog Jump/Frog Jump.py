n, k = map(int, input().split())  # 10만, 100만
intervals = [list(map(int, input().split())) for _ in range(n)]

ssum = [0 for _ in range(n)]  # 0에서 i까지 가는데 드는 점프비용
max_end = intervals[0][1]

for i in range(1, n):
    cur_start = intervals[i][0]
    ssum[i] = ssum[i - 1] + max(0, cur_start - max_end)
    max_end = max(max_end, intervals[i][1])

order = list(map(int, input().split()))  # 중복 가능

ans = 0
cur = 0
for goal in order:
    # cur->goal 사이의 점프렝스를 더하면 됨
    goal -= 1
    ans += abs(ssum[goal] - ssum[cur])
    cur = goal


print(ans)
