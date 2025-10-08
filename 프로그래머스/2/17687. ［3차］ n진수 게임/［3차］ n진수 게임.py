def add(num, base):
    if num == 0:
        return "0"
    s = ''
    a,b = num, 0
    while a:
        a,b = a//base, a%base
        if b>=10:
            b = chr(b+55)
        s += str(b)
    return s[::-1]

def solution(n, t, m, p):
    answer = ''
    
    s = ''
    cnt = 0
    tube_turn_idx = p-1
    i = 0
    num = 0
    while cnt < t:
        if i== len(s):
            s += add(num, n)
            num += 1
        
        if i%m == tube_turn_idx:
            answer += s[i]
            cnt += 1
        i+=1
        
    return answer


"""
2진법
미리 구할 수 4개 (result의 길이)
인원 2, 튜브 1번순서

t   t   t   t
0 1 1 0 1 1 1 0 0

0: 0
1: 1
2: 10
3: 11
4: 100
5: 101
6
7
8

"""