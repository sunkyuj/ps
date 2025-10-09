# 4:05
import bisect

def solution(scores):
    scores = list(map(tuple, scores))
    me = scores[0]
    answer = 0
    # 어떤 사람이 둘다 낮은거 있으면 못받음
    
    n = len(scores) # 10만
    insen = [0]*n
    scores.sort(key = lambda x: (x[0],-x[1])) # 근무평가 기준으로 정렬
    
    rem = set()
    prev_st = [(-1, 100001)]
    for i in range(n):
        a,b = scores[i] # a는 오름차순 고정, b는 내려가는것만 허용
        # 만약 b 올라갔다? 그놈 나가리임
        while prev_st[-1][1] < b:
            prev = prev_st.pop()
            rem.add(prev) 
        prev_st.append(scores[i])
    
    if me in rem:
        return -1
    
    insen = [sum(scores[i]) for i in range(n) if scores[i] not in rem]
    insen.sort()
    rank = bisect.bisect_right(insen, sum(me))
    return len(insen) - rank + 1