def solution(targets):
    answer = 0
    # end 기준으로 정렬 -> 
    targets.sort(key=lambda x:x[1])
    shoot_lb = 0
    for s,e in targets:
        if s >= shoot_lb:
            answer += 1
            shoot_lb=e
            
    
        
    
    return answer
