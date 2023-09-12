def solution(A, B):
    answer = 0
    
    A.sort(reverse=1)
    B.sort(reverse=1)
    
    i,j = 0, len(B)-1
    for a in A:
        if a<B[i]:
            answer+=1
            i+=1
        else:
            j-=1
        
        if i>j:
            break
    
    return answer

