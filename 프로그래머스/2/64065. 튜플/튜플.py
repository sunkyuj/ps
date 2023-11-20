def solution(s):

    s = s[2:-2]
    li = s.split("},{")
    for i in range(len(li)):
        li[i] = set(map(int,li[i].split(",")))
    li.sort(key=len)
    
    ans_set = li[0]
    answer = [x for x in ans_set]
    for i in range(1,len(li)):
        new = li[i] - li[i-1]
        ans_set.update(new)
        answer += [x for x in new]
        
    return answer

