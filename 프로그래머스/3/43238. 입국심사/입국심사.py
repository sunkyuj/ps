def able(n,times, total):
    for time in times:
        q = total//time
        n -= q
        if n<=0:
            return 1
    return 0

def solution(n, times):
    answer = 0
    times.sort()
    max_t = max(times)*n
    
    m,M = 1, max_t
    
    while m < M:
        mid = (m+M)//2
        
        if able(n,times, mid):
            M = mid
        else:
            m = mid+1
        
    """
                      1                   2
    1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0
    a=a=a=a=a=a=a c=c=c=c=c=c=c e=e=e=e=e=e=e f=f=f=f=f=f=f
    b=b=b=b=b=b=b=b=b=b d=d=d=d=d=d=d=d=d=d
    
    """

    return M