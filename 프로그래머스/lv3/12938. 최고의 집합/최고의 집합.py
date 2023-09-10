def solution(n, s):
    val = s//n
    rem = s%n
    if val<1:
        return [-1]
    
    answer = [val]*n 
    for i in range(rem):
        answer[-i-1]+=1
    
    return answer


"""
3 7 (7/3 = 2.33, 7//3=2, 7%3=1)

1 1 5
1 2 4
1 3 3
1 4 2
1 5 1

2 1 4
2 2 3
2 3 2
2 4 1

3 1 3
3 2 2
3 3 1

4 1 2
4 2 1

5 1 1

50//4=12, 50%4=2

12 12 13 13
"""

