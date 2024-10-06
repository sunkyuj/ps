alp = {}
idx = 0

def get_index(w):
    global idx
    s = w[0]
    ret = alp[s]
    for i in range(1,len(w)):
        s+=w[i]
        if s not in alp:
            idx+=1
            alp[s] = idx
            return ret, max(len(s)-1,1)
        ret = alp[s]
    return ret, len(s)
    


def solution(msg):
    global idx
    answer = []
    
    # 길이 1 초기화
    for x in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
        idx += 1
        alp[x] = idx
    
    i = 0
    while i < len(msg):
        ret, jump = get_index(msg[i:])
        answer.append(ret)
        i += jump
    
    return answer