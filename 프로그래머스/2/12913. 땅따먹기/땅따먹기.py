def get_prev_max(prev_dp, cur):
    ret = 0
    for j in range(4):
        if j==cur:
            continue
        ret = max(ret,prev_dp[j])
    return ret

def solution(land):
    answer = 0
    n =  len(land)
    # dp[i][j] = i번째 열에서 j번 골랐을 때 최댓값
    dp = [[0,0,0,0] for _ in range(n)]
    dp[0] = land[0]
    for i in range(1,n):
        for j in range(4):
            dp[i][j] = get_prev_max(dp[i-1], j) + land[i][j]
                

    return max(dp[-1])