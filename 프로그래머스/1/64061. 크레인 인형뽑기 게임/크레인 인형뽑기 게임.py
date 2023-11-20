def solution(board, moves):
    answer = 0
    n,m = len(board), len(board[0])
    stacks = [[] for _ in range(m)]
    bucket = []
    for j in range(m):
        for i in range(n-1,-1,-1):
            if board[i][j]==0:
                break
            stacks[j].append(board[i][j])
    for move in moves:
        j = move-1
        if stacks[j] == []:
            continue
        bucket.append(stacks[j].pop())
        if len(bucket)>=2 and bucket[-1] == bucket[-2]:
            answer+=2
            bucket.pop()
            bucket.pop()
    return answer