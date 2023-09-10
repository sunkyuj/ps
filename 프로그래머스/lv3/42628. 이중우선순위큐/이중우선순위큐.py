from heapq import heappop, heappush
def solution(operations):
    answer = []
    maxh,minh = [],[]
    for op in operations:
        num = int(op[2:])        
        if op[0]=="I":
            # insert
            heappush(minh,num)
            heappush(maxh,-num)
            
        else:
            if not minh:
                continue
                
            if num==1: 
                # del max
                x=-heappop(maxh)
                for i in range(len(minh)-1,-1,-1):
                    if minh[i]==x:
                        del minh[i]
                
            else:
                # del min
                x=heappop(minh)
                for i in range(len(maxh)-1,-1,-1):
                    if maxh[i]==x:
                        del maxh[i]
    if not minh:
        return [0,0]
    return [-heappop(maxh),heappop(minh)]