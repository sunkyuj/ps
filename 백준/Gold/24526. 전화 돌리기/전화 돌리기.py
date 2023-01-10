import sys

sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m


def dfs(v):
    global visit
    visit[v] = 1
    has_cycle = 0
    if v in conn:
        for to in conn[v]:
            if cycle[to] or visit[to] == 1:  # cycle!
                has_cycle = 1
            elif visit[to] == 2:  # no cycle, `to` is clean
                has_cycle |= 0
            else:  # no cycle, never visited
                has_cycle |= dfs(to)

    if has_cycle:
        return 1
    else:
        visit[v] = 2
        return 0


n, m = map(int, input().split())
root = [i for i in range(n + 1)]
cycle = [0 for i in range(n + 1)]
visit = [0 for i in range(n + 1)]


conn = {}
for i in range(m):
    frm, to = map(int, input().split())
    conn.setdefault(frm, set())
    conn[frm].add(to)

for i in range(1, n + 1):
    if not visit[i]:
        dfs(i)


print(visit.count(2))
