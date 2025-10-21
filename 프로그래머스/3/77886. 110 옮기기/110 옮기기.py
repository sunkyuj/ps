is110 = lambda st: len(st) >= 3 and st[-1] == "0" and st[-2] == "1" and st[-3] == "1"

def f(s):
    st = []
    cnt = 0
    for c in s:
        st.append(c)
        if is110(st):
            st.pop()
            st.pop()
            st.pop()
            cnt+=1 
    
    last0 = -1
    for i in range(len(st)-1,-1,-1):
        if st[i] == "0":
            last0 = i
            break

    return "".join(st[:last0+1]) + "110"*cnt + "".join(st[last0+1:])
    
def solution(ss): # 길이 백만
    answer = []

    for s in ss: # 100만
        # n이나 nlogn 까지 괜찮을듯 (ss 모든 원소의 길이 합이 100만)
        answer.append(f(s))
        
    return answer