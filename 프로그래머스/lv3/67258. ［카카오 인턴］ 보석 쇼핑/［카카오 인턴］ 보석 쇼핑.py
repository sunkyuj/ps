from collections import defaultdict

def solution(gems):
    answer = [1,len(gems)]
    min_len = len(gems)
    
    goal_len = len(set(gems))
    d = defaultdict(int)
    n = len(gems)
    cur = set()
    
    i,j = 0,-1
    while i<n and j<n:
        if len(cur) < goal_len:
            if j+1==n:
                break
            j+=1
            if d[gems[j]]==0:
                cur.add(gems[j])
            d[gems[j]]+=1
        elif len(cur) > goal_len:
            d[gems[i]]-=1
            if d[gems[i]]==0:
                cur.remove(gems[i])
            i+=1
                
        else:
            if j-i+1<min_len:
                min_len = j-i+1
                answer = [i+1,j+1]
            
            d[gems[i]]-=1
            if d[gems[i]]==0:
                cur.remove(gems[i])
            i+=1
            if i==n:
                break
            if i>j:
                if j+1==n:
                    break
                j+=1
                if d[gems[j]]==0:
                    cur.add(gems[j])
                d[gems[j]]+=1
            
            
                
    
    return answer