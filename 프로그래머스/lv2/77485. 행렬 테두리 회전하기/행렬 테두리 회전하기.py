def solution(rows, columns, queries):
    answer = []
    board = [[i*columns+j for j in range(1,columns+1)] for i in range(rows)]
    
    for si,sj,ei,ej in queries:
        si,sj,ei,ej = si-1,sj-1,ei-1,ej-1
        
        i,j = si,sj
        cur = board[i][j]
        
        min_val = cur
        
        while j<ej:
            nxt = board[i][j+1]
            board[i][j+1] = cur
            cur = nxt
            min_val=min(min_val,cur)
            j+=1
        while i<ei:
            nxt = board[i+1][j]
            board[i+1][j] = cur
            cur = nxt
            min_val=min(min_val,cur)
            i+=1
        while j>sj:
            nxt = board[i][j-1]
            board[i][j-1] = cur
            cur = nxt
            min_val=min(min_val,cur)
            j-=1
        while i>si:
            nxt = board[i-1][j]
            board[i-1][j] = cur
            cur = nxt
            min_val=min(min_val,cur)
            i-=1     
            
        answer.append(min_val)
    return answer