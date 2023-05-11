def solution(sequence, k):
    n = len(sequence)
    answer = [-1,-1]
    ans_len = 999999999
    i,j = 0, 1
    local_sum = sequence[0]
    
    while i<j and j<=n:
        if local_sum < k:
            if j==n:
                break
            local_sum+=sequence[j]
            j+=1
        elif local_sum > k:
            local_sum-=sequence[i]
            i+=1
        else:
            if ans_len>j-i+1:
                ans_len=j-i+1
                answer[0],answer[1] = i,j-1
            if j==n:
                break
            local_sum+=sequence[j]
            j+=1
    return answer