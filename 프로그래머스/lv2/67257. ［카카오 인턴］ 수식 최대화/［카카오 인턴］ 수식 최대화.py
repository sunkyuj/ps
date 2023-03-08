def postfix(exp,pri):
    result, st = [], []
    for el in exp:
        if type(el) == int: # 숫자면 곧바로 result에 넣음
            result.append(el)
            
        else: # 연산자면 
            while st and pri[el] <= pri[st[-1]] : # 지금 뽑은거보다 우선순위 높은거 다 뽑음
                result.append(st.pop())   
            st.append(el) # 지금 뽑은거 스택에 넣어줌

    while st: # 스택에 남은 연산자 다 붙임
        result.append(st.pop())   
        
    return result
    
def cal(exp, pri):
    post_exp = postfix(exp,pri)
    st = []
    for el in post_exp:
        if type(el) == int: 
            st.append(el)
        else:
            b = st.pop()
            a = st.pop()
            st.append(eval(str(a)+el+str(b)))
    return st[0]

def solution(expression):
    answer = 0
    priorities = [
        {'+':3, '-':2, '*':1},
        {'+':3, '*':2, '-':1},
        {'-':3, '+':2, '*':1},
        {'-':3, '*':2, '+':1},
        {'*':3, '+':2, '-':1},
        {'*':3, '-':2, '+':1},
    ]
    
    exp_li = []
    prev = 0
    for i in range(len(expression)):
        if expression[i] in "*+-":
            exp_li.append(int(expression[prev:i]))
            exp_li.append(expression[i])
            prev = i+1
    exp_li.append(int(expression[prev:]))
    
    for pri in priorities:
        answer = max(answer, abs(cal(exp_li,pri)))
    return answer