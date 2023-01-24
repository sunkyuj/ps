from itertools import combinations

def solution(orders, course):
    answer = []
    d = {}
    maxes = {i:0 for i in course}
    for order in orders:
        l = len(order)
        for i in course:
            for c in combinations(order,i):
                key = "".join(sorted(list(c)))
                d.setdefault(key,0)
                d[key]+=1
                maxes[i] = max(maxes[i],d[key])
                
    for k,v in d.items():
        if maxes[len(k)]>=2 and maxes[len(k)] == v:
            answer.append(k)
            
    answer.sort()
    return answer