def to_num(bn):
    result = 0
    i = 1
    for x in reversed(bn):
        result+= i*x
        i*=2
    return result

def f(n):
    bn = list(map(int,bin(n)[2:]))
    i = len(bn)-1
    
    while i>=0:
        if bn[i] == 0: # found 0
            break
        i-=1
    
    if i == len(bn)-1: # tail is 0
        return n+1
    
    if i == -1:
        bn = [0] + bn
        i = 0

    bn[i],bn[i+1] = 1,0
    
    return to_num(bn)

def solution(numbers):
    answer = []
    for n in numbers:
        answer.append(f(n))
    return answer

# 2**50 >= 10**15

# all 0 then +1
# all 1 then 0111 -> 1111 -> 1011
# else then 