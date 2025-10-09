# 12:30

MAX = 999999999

def solution(n, S, A, B, fares):
    answer = MAX
    
    # n 200
    dist = [[MAX for _ in range(n+1)] for _ in range(n+1)]
    
    for i,j,cost in fares:
        dist[i][j] = cost
        dist[j][i] = cost
        
    for i in range(1, n+1):
        dist[i][i] = 0
        
    # i - k - j
    for k in range(1,n+1):
        for i in range(1,n+1):
            for j in range(1,n+1):
                val = dist[k][i] + dist[k][j]
                dist[i][j] = min(dist[i][j], val)
                dist[j][i] = min(dist[j][i], val)
                
    # s 에서 동시에 가는거 경로 n개 뽑기, 거기서 a가는거+b가는거
    for k in range(1,n+1): # k까지 같이
        answer = min(answer, dist[S][k]+dist[k][A]+dist[k][B])
            
    # 두사람 최저요금
    return answer