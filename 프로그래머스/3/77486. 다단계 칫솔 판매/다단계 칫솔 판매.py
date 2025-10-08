import math

def solution(enroll, referral, seller, amount):
    global parent, selled, gain
    answer = []
    
    parent = { enroll[i]: referral[i] for i in range(len(enroll))}
    
    gain = { enroll[i]: 0 for i in range(len(enroll))}
    gain['-'] = 0
    
    for i in range(len(seller)):
        dfs(seller[i],amount[i]*100)
    
    # print(gain)
    for e in enroll:
        answer.append(gain[e])
    return answer

def dfs(cur, money):
    global parent, selled, gain
    
    tax = money // 10
    my = money - tax
    
    gain[cur] += my
    
    if tax and cur != '-':
        dfs(parent[cur], tax)
    
        
    
    
    