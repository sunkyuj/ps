from collections import deque


def solution(players, m, k):
    answer = 0
    servers = 0
    time = 0
    q = deque()
    for p in players:
        floor = servers*m
        ceil = (servers+1)*m
        if p >= m and p >= ceil:
            add = 1
            while ceil + m*add <= p:
                add += 1
            answer += add
            servers += add
            q.append((add,time+k))
        
        time += 1
        while q:
            add,end = q.popleft()
            if end == time:
                servers -= add
            else:
                q.appendleft((add,end))
                break
            
        
    return answer