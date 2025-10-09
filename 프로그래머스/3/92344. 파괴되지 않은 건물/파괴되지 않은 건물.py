# 5:40
def solution(board, skill):
    answer = 0 
    # board 1000*1000
    # skill 250,000
    
    # 단순히 차례대로 구현하면 시간초과
    # type1: attack, type2: heal
    
    # Q * N*M == 25만 * 1000*1000 == 25만 * 100만 == 2500억
    # 누적합 방식으로 풀이 O(Q*1) + O(N*M)
    n,m = len(board), len(board[0])
    sboard = [[0 for _ in range(m+1)] for _ in range(n+1)] # 누적합 보드
    """
    N 0 0 -N ==> N N N 0
    0 0 0 0      N N N 0
    0 0 0 0      N N N 0
    -N 0 0 N     0 0 0 0
    
     A  B  0  0 -A -B
     0  0  0  0  0  0
    -A  0  0  0  A  0
     0  0  0  0  0  0
     0  0  0  0  0  0
     0 -B  0  0  0  B
     
     A  A+B A+B B  B  0
     0  0   0   0  0  0
    -A  0   0   0  A  0
     0  0   0   0  0  0
     0  0   0   0  0  0
     0 -B   0   0  0  B
    """
    
    for type, r1, c1, r2, c2, degree in skill:
        op = -1 if type == 1 else 1
        sboard[r1][c1] += op*degree
        sboard[r2+1][c1] += -op*degree
        sboard[r1][c2+1] += -op*degree
        sboard[r2+1][c2+1] += op*degree
        
    # ->
    for i in range(n+1):
        for j in range(1, m+1):
            sboard[i][j] = sboard[i][j-1] + sboard[i][j]

    # v
    for j in range(m+1):
        for i in range(1, n+1):
            sboard[i][j] = sboard[i-1][j] + sboard[i][j]
    
    for i in range(n):
        for j in range(m):
            board[i][j] += sboard[i][j]
            if board[i][j] >0:
                answer+=1
    
    return answer