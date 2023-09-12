def solution(n, stations, w):
    answer = 0
    
    covered = []
    for st in stations:
        if covered and covered[-1][1] >= st-w - 1: # 전파 겹치거나 맞닿아있으면 합침
            covered[-1][1] = min(n,st+w)
        else:
            covered.append([max(1,st-w),min(n,st+w)])
    
    uncovered = []
    start = 1
    for cov_s, cov_e in covered:
        if start < cov_s:
            uncovered.append([start,cov_s-1])
        start = cov_e+1  
    if start <= n:
        uncovered.append([start,n])
    
    
    for s,e in uncovered:
        l = e-s+1
        wave = w*2+1
        answer += l//wave + (1 if l%wave else 0)
    
    return answer