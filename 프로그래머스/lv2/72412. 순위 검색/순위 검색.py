def lb(arr, k):
    s,e = 0,len(arr)-1
    while s<=e:
        mid = (s+e)//2
        if arr[mid] >= k:
            e = mid-1
        else:
            s = mid+1
    return s

# 0 1 2 3 4 5 6 7 8 9 10 11 12
# 1 1 1 1 1 1 2 2 2 2  7  7  7 
def solution(info, query):
    answer = []
    d = {}
    
    # 5400000
    for lang in ["-", "cpp", "java", "python"]: # 4
        for part in ["-", "backend", "frontend"]: # 3
            for career in ["-", "junior", "senior"]: # 3
                for food in ["-", "chicken", "pizza"]: # 3 = 108
                    d[lang+part+career+food] = []
                    
                    for info_str in info: # 50000
                        l,p,c,f,score = map(str,info_str.split())
                        if (l == lang or lang == "-") and (p == part or part == "-") and (c == career or career == "-") and (f == food or food == "-"):
                            d[lang+part+career+food].append(int(score))
                    d[lang+part+career+food].sort()

                            
    for q in query: # 100000
        lang,part,career,food_score = map(str, q.split(" and "))
        food,score = map(str,food_score.split())
        
        cnt = len(d[lang+part+career+food]) - lb(d[lang+part+career+food],int(score))
        
        answer.append(cnt)
                        
                    
                    
    return answer