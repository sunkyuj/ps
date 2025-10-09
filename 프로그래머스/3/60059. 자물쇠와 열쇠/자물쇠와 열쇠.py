# 8:19
in_range = lambda y,x: 0<=y<n and 0<=x<n

def apply(lock, key, sy, sx):
    global n, m
    
    filled = []
    for i in range(sy, sy+m):
        for j in range(sx, sx+m):
            if not in_range(i,j) or key[-sy+i][-sx+j] == 0:
                continue
                
            if lock[i][j] == 1:
                return False, filled
            else:
                lock[i][j] = 1
                filled.append((i,j))
    
    return True, filled

def check(lock):
    for r in lock:
        for c in r:
            if c == 0:
                return 0
    return 1

def solution(key, lock):
    answer = True
    # 3 <= M <= N <= 20
    
    # 모든 홈을 채워야함
    # 자물쇠 영역 내에서 열쇠랑 겹치면 안됨
    
    # 열쇠 4개 만들기
    global n, m
    n,m = len(lock), len(key)
    keys = [[[0 for _ in range(m)] for _ in range(m)] for _ in range(4)]
    for i in range(m):
        for j in range(m):
            keys[0][i][j] = key[i][j]
            keys[1][j][m-1-i] = key[i][j]
            keys[2][m-1-i][m-1-j] = key[i][j]
            keys[3][m-1-j][i] = key[i][j]
    
        
    for msy in range(-m+1, n):
        for msx in range(-m+1, n):
            for k in range(4):
                able, filled = apply(lock, keys[k], msy, msx)
                if able and check(lock):
                    return True
                for y,x in filled:
                    lock[y][x] = 0
            
    return False