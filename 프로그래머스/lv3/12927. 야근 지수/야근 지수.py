from heapq import heappush, heappop
def solution(n, works):
    answer = 0
    hq = []
    for w in works:
        heappush(hq,-w)
    
    while n:
        x = heappop(hq)
        if x==0:
            break
        x+=1
        heappush(hq,x)
        n-=1
    
    for x in hq:
        answer+=x*x
    return answer