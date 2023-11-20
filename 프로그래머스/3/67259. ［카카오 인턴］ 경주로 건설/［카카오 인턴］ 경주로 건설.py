from heapq import heappush, heappop

dydx = [(1,0), (0,1), (-1,0), (0,-1)]
MAX = 500*25*25 +1

def solution(board):
    n = len(board)
    in_range = lambda y,x: 0<=y<n and 0<=x<n
    
    visit = [[[MAX,MAX,MAX,MAX] for _ in range(n)] for _ in range(n)]
    hq = [(0,0,0,0), (0,0,0,1)] # cost, y, x, dir
    visit[0][0][0] = 0
    visit[0][0][1] = 0
    
    while hq:
        cost, y,x,dir = heappop(hq)
        if (y,x) == (n-1,n-1):
            return cost
        if cost > visit[y][x][dir]:
            continue

        for k in range(4):
            dy,dx = dydx[k]
            ny,nx = y+dy, x+dx
            ncost = cost + 100 + (500 if k!=dir else 0)
            if in_range(ny,nx) and board[ny][nx]==0 and visit[ny][nx][k] >= ncost:
                heappush(hq,(ncost,ny,nx,k))
                visit[ny][nx][k] = ncost
                
            
        
    
    
    
    