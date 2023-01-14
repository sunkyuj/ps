def check(sub):
    st = []
    for x in sub:
        st.append(x)
        if len(st)>=2 and st[-2]+st[-1] in ("()","{}","[]"):
            st = st[:-2]
        
    if st:
        return 0
            
    return 1
def solution(s):
    answer = 0
    l = len(s)
    ls = list(s) + list(s)
    
    for i in range(l):
        sub = ls[i:i+l]
        answer+=check(sub)        
    
    return answer