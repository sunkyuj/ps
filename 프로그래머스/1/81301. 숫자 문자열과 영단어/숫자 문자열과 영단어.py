from collections import deque

def solution(s):
    answer = ""
    """
    z
    o
    t t
    f f
    s s
    e
    n
    """
    num_map = {
        "zero" : 0,
        "one" : 1,
        "two" : 2,
        "three" : 3,
        "four" : 4,
        "five" : 5,
        "six" : 6,
        "seven" : 7,
        "eight" : 8,
        "nine" : 9
    }
    q = []
    
    for c in s:
        q.append(c)
        x = "".join(q)
        if "0"<= x <="9":
            answer+=q.pop()
        elif x in num_map:
            answer += str(num_map[x])
            while q != []:
                q.pop()
        
    return int(answer)