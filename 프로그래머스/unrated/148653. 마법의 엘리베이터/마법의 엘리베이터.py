def f(n,loc):
    if n==0:
        return 0
    if loc>100000000:
        return 100000000
    
    cur_num = n % (loc*10) // loc # 그 자리수에 있는 수
    up = n + loc*10 - cur_num*loc
    down = n - cur_num*loc
    
    return min(10-cur_num+f(up,loc*10),cur_num+f(down,loc*10))

def solution(storey):
    return f(storey,1)