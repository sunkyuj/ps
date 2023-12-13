import sys
sys.setrecursionlimit(10**7)
stones = list(map(int,input().split()))
visit = set()
all_same = lambda li: (li[0] == li[1]) and (li[1] == li[2])

def dfs(sts):
    if all_same(sts):
        return 1
    
    sts.sort()
    if tuple(sts) in visit:
        return 0
    visit.add(tuple(sts))

    flag = 0

    if sts[0]!=sts[1]:
        x = sts[0]
        flag |= dfs([sts[0]+x,sts[1]-x,sts[2]])
        if flag:
            return 1
    if sts[0]!=sts[2]:
        x = sts[0]
        flag |= dfs([sts[0]+x,sts[1],sts[2]-x])
        if flag:
            return 1
    if sts[1]!=sts[2]:
        x = sts[1]
        flag |= dfs([sts[0],sts[1]+x,sts[2]-x])
        if flag:
            return 1

    return flag

print(dfs(stones))