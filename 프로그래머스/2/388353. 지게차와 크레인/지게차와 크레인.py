from collections import deque
in_range = lambda y,x: 0<=y<n and 0<=x<m
dydx = [(1,0), (0,1), (-1,0), (0,-1)]

def reach(exists,reachable):
    q = deque()
    visit = set()
    q.append((0,0))
    visit.add((0,0))
    
    while q:
        y,x = q.popleft()
        
        for dy,dx in dydx:
            ny,nx = y+dy, x+dx
            if not (0<=ny<n+2 and 0<=nx<m+2) or (ny,nx) in visit:
                continue
            if ny==0 or ny==n+1 or nx==0 or nx==m+1:
                q.append((ny,nx))
                visit.add((ny,nx))
                continue
            
            if exists[ny-1][nx-1]:
                reachable[ny][nx] = 1
            else:
                q.append((ny,nx))
                visit.add((ny,nx))

def solution(storage, requests):
    global n,m
    n,m = len(storage), len(storage[0])
    answer = 0
    exists = [[1 for _ in range(m)] for _ in range(n)]
    reachable = [[0 for _ in range(m+2)] for _ in range(n+2)]
    for i in range(n+2):
        for j in range(m+2):
            if i<=1 or i>=n or j<=1 or j>=m:
                reachable[i][j] = 1
    
    
    for req in requests:
        target = req[0]
        remove = []
        for i in range(n):
            for j in range(m):
                if storage[i][j] == target:
                    if len(req) == 1:
                        if reachable[i+1][j+1]:
                            remove.append((i,j))
                    else:
                        remove.append((i,j))
        
        while remove:
            y,x = remove.pop()
            exists[y][x] = 0
            
        reach(exists,reachable)
        
    for e in exists:
        print(e)
    answer = sum([sum(e) for e in exists])
    return answer