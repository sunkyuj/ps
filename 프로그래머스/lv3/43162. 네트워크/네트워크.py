from queue import Queue

def solution(n, computers):
    answer = 0
    visit = [0 for _ in range(n)]
    q = Queue()
    for i in range(n):
        if not visit[i]:
            q.put(i)
            visit[i] = 1
            while not q.empty():
                x = q.get()
                for to in range(n):
                    if computers[x][to] and not visit[to]:
                        q.put(to)
                        visit[to] = 1
                    
            answer+=1
            
    return answer