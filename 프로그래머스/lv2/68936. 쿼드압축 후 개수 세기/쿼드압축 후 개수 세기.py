def f(y,x,l):
    ret = [0,0]
    
    same = True
    for i in range(y,y+l):
        for j in range(x,x+l):
            if board[y][x] != board[i][j]:
                same = False
                break
        if not same:
            break
            
    if same:
        ret[board[y][x]] = 1
    else:
        a = f(y,x,l//2)
        b = f(y,x+l//2,l//2)
        c = f(y+l//2,x,l//2)
        d = f(y+l//2,x+l//2,l//2)
        ret[0] = a[0] + b[0] + c[0] + d[0]
        ret[1] = a[1] + b[1] + c[1] + d[1]
    return ret

def solution(arr):
    global board
    board = arr
    answer = f(0,0,len(board))
    return answer