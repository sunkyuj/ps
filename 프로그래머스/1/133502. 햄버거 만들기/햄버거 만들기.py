def solution(ingredient):
    answer = 0
    st = []
    # 1 2 3 1 -> pop
    for x in ingredient:
        st.append(x)
        if len(st) >= 4 and (st[-4],st[-3],st[-2],st[-1]) == (1,2,3,1):
            answer += 1
            st.pop()
            st.pop()
            st.pop()
            st.pop()
            
    return answer