from itertools import combinations

def is_min(cand_set, picked_cols):
    for cand in cand_set:
        
        cont_all = True
        for x in cand:
            if x not in picked_cols:
                cont_all = False
                break
        
        if cont_all:
            return False
        
    return True
    

def solution(relation):
    answer = 0
    cand_set = set()
    
    r,c = len(relation), len(relation[0])
    
    # 뽑을 칼럼 수
    for i in range(1,r+1):
        for picked_cols in combinations(range(c),i):
            tuple_set = set()
            
            # make tuple for each row
            for row in relation:
                t = tuple()
                for col in picked_cols:
                    t+=(row[col],)
                tuple_set.add(t)
                
            if len(tuple_set)==r:
                if is_min(cand_set,picked_cols):   
                    cand_set.add(picked_cols)
                    answer+=1
                    
    return answer