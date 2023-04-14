from itertools import permutations
"""
1 5
2 55 5+5 5-5 5*5 5/5 
3 555
4 5555
5 55555

1: 5
2: 1op1
3: 1op2, 2op1 
4: 1op3, 2op2, 3op1
5: 1op4, 2op3, 3op2, 4op1
"""

def solution(N, number):
    global ans
    ans = 9
    
    able = {i : {int(str(N)*i)} for i in range(1,9)} # N, NN, NNN ...
    
    for i in range(2,9):
        for j in range(1,i):
            for a in able[j]:
                for b in able[i-j]:
                    able[i].add(a+b)
                    able[i].add(a-b)
                    able[i].add(a*b)
                    if b:
                        able[i].add(a//b)
        
    for i in range(1,9):
        if number in able[i]:
            return i
                
    
    if ans == 9:
        return -1
    return ans