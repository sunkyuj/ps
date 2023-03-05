d = [(1,0), (0,1), (-1,-1)]
def solution(n):
    answer = []
    board = [[0 for _ in range(n)] for _ in range(n)]
    
    cnt = 1
    y,x,k = -1,0,-1
    for move in range(n,0,-1):
        k = (k+1)%3
        for i in range(move):
            y,x = y + d[k][0], x + d[k][1]
            board[y][x] = cnt
            cnt+=1
    for i in range(n):
        answer += board[i][:i+1]
    return answer



