def f(idx):
    global g_users,g_emoticons,n,en,max_plus_service,max_benefit
    if idx == en:
        # 우선순위: (플러스서비스, 총 이윤)
        
        plus_service = 0
        benefit = 0
        
        # 총 이윤 계산
        for i in range(n): # user
            user_buy_rate, user_limit = g_users[i]
            user_cost = 0
            user_plus_service = 0
            for e in range(en): # emo
                if user_buy_rate<=sale_rate[e]:
                    user_cost+=g_emoticons[e]*(100-sale_rate[e])//100
                if user_cost>=user_limit:
                    user_cost = 0
                    user_plus_service = 1
                    break
            
            plus_service+=user_plus_service
            benefit+=user_cost
        
        # 최대값 계산
        if max_plus_service < plus_service or (max_plus_service == plus_service and max_benefit < benefit):
            max_plus_service = plus_service
            max_benefit = benefit
            
        return
    
    sale_rate.append(10)
    f(idx+1)
    sale_rate.pop()
    
    sale_rate.append(20)
    f(idx+1)
    sale_rate.pop()
    
    sale_rate.append(30)
    f(idx+1)
    sale_rate.pop()
    
    sale_rate.append(40)
    f(idx+1)
    sale_rate.pop()
    
    
def solution(users, emoticons):
    global n,en,sale_rate,g_users,g_emoticons,max_plus_service,max_benefit
    g_users,g_emoticons = users,emoticons
    max_plus_service = 0
    max_benefit = 0
    
    n = len(users)
    en = len(emoticons)
    # 할인율은 10 20 30 40% 중 하나
    # users 100, emoticons 7
    sale_rate = []
    
    f(0)
    
    return [max_plus_service, max_benefit]