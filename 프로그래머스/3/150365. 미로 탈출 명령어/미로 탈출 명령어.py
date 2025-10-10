# 9:13
from collections import deque
MAX = 'z'*2501
# dlru 순
dydxds = [[1,0,"d"], [0,-1,"l"], [0,1,"r"], [-1,0,"u"]]

def solution(n, m, y, x, r, c, k):
    inrange = lambda y,x: 0<=y<n and 0<=x<m
    answer = MAX
    y-=1
    x-=1
    r-=1
    c-=1
    
    # 이동 거리가 k여야 하고, 두번 이상 방문 가능
    
    board = [["" for _ in range(m)] for _ in range(n)]
    # board[i][j] = board[i][j] 위치에 도달할수있는 최소문자열 (길이가 k일것)
    
    q = deque() # 
    q.append((y,x))
    
    while q:
        i,j = q.popleft()
        s = board[i][j]
        if len(s) == k:
            if (i,j) == (r,c):
                return s
            continue
        
        # 현재 칸에서 갈수있는거 큐에 넣음
        for dy,dx,ds in dydxds:
            ny,nx = i+dy, j+dx
            if not inrange(ny,nx):
                continue
            
            ns = s+ds
            # 다음 칸이 이번 길이로는 한 번도 도달 안했거나, 이번에 가면 더 좋은 경로라면
            if len(board[ny][nx]) < len(s)+1 or board[ny][nx] > ns:
                q.append((ny,nx))
                board[ny][nx] = ns
                
    return "impossible"