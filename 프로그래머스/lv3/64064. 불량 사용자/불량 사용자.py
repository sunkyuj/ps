def check(b,u):
    if len(u)!=len(b):
        return 0
    
    for i in range(len(u)):
        if b[i]=="*":
            continue
        if b[i]!=u[i]:
            return 0
    return 1
            
    
def f(bid, cnt, user_list, ban_list):
    global answer_set, visit
    bn = len(ban_list)
    if bid == bn:
        if cnt==bn:
            answer_set.add(tuple(visit))
        return 
    
    banned_user = ban_list[bid]
    
    for i in range(len(user_list)):
        if visit[i]:
            continue
        user = user_list[i]
        if check(banned_user, user):
            visit[i] = 1
            f(bid+1, cnt+1, user_list, ban_list)
            visit[i] = 0

def solution(user_id, banned_id):
    global answer_set, visit
    answer_set = set()
    visit = [0] * len(user_id)
    
    f(0,0, user_id, banned_id)
    
    return len(answer_set)