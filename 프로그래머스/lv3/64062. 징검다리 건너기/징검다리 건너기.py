def check(stones, k, level):
    cnt = 0
    for stone in stones:
        if stone <= level:
            cnt+=1
        else:
            cnt=0
            
        if cnt == k:
            return 0
    return 1
        
        
    
def solution(stones, k):
    answer = 0
    low, high = 0, max(stones)
    
    while low<=high:
        mid = (low+high)//2
        # print(low,mid,high)
        if check(stones,k,mid):
            # print("can")
            low = mid+1
            answer = max(answer,mid+1)
        else:
            # print("nono")
            high = mid-1
            
    return answer