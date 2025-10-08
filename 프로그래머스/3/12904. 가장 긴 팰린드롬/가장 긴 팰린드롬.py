def solution(s):
    answer = 0
    
    # pal[len][s_idx]
    pal = [[0 for _ in range(len(s)-l, -1, -1)] for l in range(len(s)+1)]
    # 1
    for i in range(len(s)):
        pal[1][i] = 1
    # 2
    for i in range(len(s)-1):
        pal[2][i] = 1 if s[i] == s[i+1] else 0
    # n
    for l in range(3,len(s)+1):
        for i in range(len(s)-l+1):
            start = i
            end = start+l-1
            if pal[l-2][i+1] and s[start] == s[end]:
                pal[l][i] = 1
    
    for l in range(1,len(s)+1):
        if sum(pal[l]):
            answer = l
    return answer