from itertools import combinations

def allpass(cset, q_sets, ans):
    global m
    for i in range(m):
        qset = q_sets[i] 
        u = cset & qset
        if len(u) != ans[i]:
            return 0
    return 1

def solution(n, q, ans):
    global m
    answer = 0
    # 비번은 1부터 n(30)까지 서로 다른 정수 5개 오룸차순
    
    m = len(q) # 시도 횟수
    q_sets = list(map(set,q))
    
    combs = list(combinations(range(1,n+1),5))
    for comb in combs:
        cset = set(comb)
        if allpass(cset, q_sets, ans):
            answer += 1
            
    return answer