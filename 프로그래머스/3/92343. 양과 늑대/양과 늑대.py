# 2:24
from collections import deque

def solution(info, edges):
    answer = 0
    # info len 최대 17임, 2의 17승 해도 10만 정도
    
    childs = { i: set() for i in range(len(info)) }
    for p,c in edges:
        childs[p].add(c)
    
    q = deque() # cur, sheeps, wolfs, adj
    q.append((0,[],[],[]))
    
    while q:
        cur, sheeps, wolfs, can_go = q.popleft()
        sheeps, wolfs, can_go = sheeps[:], wolfs[:], can_go[:]
        if info[cur] == 0:
            sheeps.append(cur)
        else:
            wolfs.append(cur)
        if len(sheeps) <= len(wolfs):
            continue
        
        can_go.extend(childs[cur])
        answer = max(answer, len(sheeps))

        for nxt in can_go:
            if nxt not in sheeps and nxt not in wolfs:
                state = (nxt, sheeps, wolfs, can_go)
                q.append(state)
    
    return answer