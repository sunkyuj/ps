n = int(input())
nodes = list(map(int, input().split()))
erase = int(input())

conn = {i: set() for i in range(n)}
roots = set()
for i in range(n):
    if nodes[i] == -1:
        roots.add(i)
    else:
        conn[nodes[i]].add(i)


def dfs(v):
    if not conn[v]:  # is leaf
        return 1

    leafs = 0
    for node in conn[v]:
        leafs += dfs(node)
    return leafs


par = nodes[erase]
if par == -1:  # is root
    roots.remove(erase)
else:
    conn[par].remove(erase)

ans = 0
for root in roots:
    ans += dfs(root)
print(ans)
