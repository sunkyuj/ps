def find(v):
    if root[v] == v:
        return v
    root[v] = find(root[v])
    return root[v]


def union(v1, v2):
    r1 = find(v1)
    r2 = find(v2)
    if r1 > r2:  # r1이 크면 바꿈
        r1, r2 = r2, r1
    root[r2] = r1  # 항상 r1이 작게끔


n, m, k = map(int, input().split())
# n<=3만, m<=10만, k<=3000
candy = list(map(int, input().split()))
root = [i for i in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    union(find(a), find(b))


d = {}  # d[r] = [candy sum, child num]
for i in range(1, n + 1):
    r = find(i)
    d.setdefault(r, [0, 0])
    d[r][0] += candy[i - 1]
    d[r][1] += 1

li = list(d.values())
li.sort(key=lambda x: (x[1], x[0]))
dp = [[0 for _ in range(k + 1)] for _ in range(len(li))]  # dp[k_limit][i] = max candy

for i in range(len(li)):  # i번까지만 탐색
    for k_limit in range(2, k + 1):
        cur_candy, cur_child = li[i]
        if k_limit > cur_child:
            dp[i][k_limit] = max(dp[i - 1][k_limit - cur_child] + cur_candy, dp[i - 1][k_limit])
        else:
            dp[i][k_limit] = dp[i - 1][k_limit]
print(dp[len(li) - 1][k])

