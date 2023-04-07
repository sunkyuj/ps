n = int(input())
tree = {}


def dfs(t, idx):
    if idx == len(info):
        return

    if info[idx] not in t:
        t.setdefault(info[idx], {})

    dfs(t[info[idx]], idx + 1)


def print_tree(t, level):
    nodes = list(t)
    nodes.sort()
    for node in nodes:
        print("--" * level, node, sep="")
        print_tree(t[node], level + 1)


for i in range(n):
    info = input().split()[1:]
    dfs(tree, 0)

print_tree(tree, 0)

"""

B-A

A-B-C-D
\_C

"""
