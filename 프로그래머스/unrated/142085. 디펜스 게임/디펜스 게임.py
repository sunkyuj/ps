from queue import PriorityQueue

def solution(n, k, enemy):
    answer = 0
    l = len(enemy)
    pq = PriorityQueue()
    
    cost = 0
    for i in range(l):
        
        if k>0: # 무적권 남은 경우
            pq.put(enemy[i])
            k-=1
            answer+=1
            continue
        
        x = pq.get()
        if x<enemy[i] and cost+x<=n:
            cost+=x
            pq.put(enemy[i])
            answer+=1
        elif cost+enemy[i] <= n:
            pq.put(x)
            cost+=enemy[i]
            answer+=1
        else:
            break
                     
    
    return answer