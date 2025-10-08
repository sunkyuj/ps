from heapq import heappop, heappush

def solution(n, roads, sources, destination):
    answer = []
    # n 10만, roads 50만
    
    conn = { i:set() for i in range(1,n+1)}
    for a,b in roads:
        conn[a].add(b)
        conn[b].add(a)
    
    MAX = 1000001
    dist = [MAX for _ in range(n+1)]
    dist[destination] = 0
    hq = [] # (d, num)
    heappush(hq, (0, destination))
    
    while hq:
        d, num = heappop(hq)
        if dist[num] < d:
            continue
        
        for nxt in conn[num]:
            if dist[nxt] > d+1:
                dist[nxt] = d+1
                heappush(hq, (d+1, nxt))
        
    for s in sources:
        ans = dist[s] if dist[s]!=MAX else -1
        answer.append(ans)
    return answer