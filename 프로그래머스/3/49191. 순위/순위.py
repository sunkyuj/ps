   
def solution(n, results):
    answer = 0

    wins = { i: set() for i in range(1,n+1)} # wins[x] = x가 이기는 애들
    loses = { i: set() for i in range(1,n+1)} # loses[x] = x가 지는 애들
    for a,b in results:
        wins[a].add(b)
        loses[b].add(a)
    
    
    for a in range(1,n+1):        
        weaker = wins[a] # a가 이기는 애들
        stronger = loses[a] # a가 지는 애들
        
        for weak in weaker: # a > b면, a보다 센 애들 > b
            loses[weak].update(stronger)
        for strong in stronger: # a < b면, a보다 약한 애들 < b
            wins[strong].update(weaker)
            
    cnts = [0]*(n+1)
    for i in range(1,n+1):
        cnts[i] = len(wins[i]) + len(loses[i])

    return cnts.count(n-1)