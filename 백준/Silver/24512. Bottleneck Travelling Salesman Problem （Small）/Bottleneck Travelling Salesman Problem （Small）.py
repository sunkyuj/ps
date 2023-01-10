import sys

sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m

MAX = 100000000
n, m = map(int, input().split())
cost = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
for i in range(m):
    a, b, c = map(int, input().split())
    cost[a][b] = c

ans = MAX
ans_path = ""


def f(cur, idx, max_val, path):
    if idx == (1 << n) - 1:
        global ans, ans_path, start
        if cost[cur][start]:
            max_val = max(max_val, cost[cur][start])
            if ans > max_val:
                ans = max_val
                ans_path = path
        return

    for to in range(1, n + 1):
        if cost[cur][to]:
            mask = 1 << (to - 1)
            if idx & mask:  # 이미 방문
                continue
            new_max = max(max_val, cost[cur][to])
            if new_max < ans:
                # visit[idx | mask] = min(visit[idx | mask], new_max)
                f(to, idx | mask, new_max, path + str(to))


for start in range(1, n + 1):
    # visit = [MAX for _ in range(1 << n)]
    # visit[1 << (i - 1)] = 0
    f(start, 1 << (start - 1), 0, str(start))

if ans == MAX:
    print(-1)
    exit()

print(ans)
for x in ans_path:
    print(x, end=" ")

"""
5 10
1 2 3
2 3 3
3 4 3 
4 5 3 
5 1 10
2 4 6
4 1 6
1 5 6
5 3 6
3 2 9

"""
