MOD = 1000000007

def solution(n, money):
    answer = 0
    
    # n 10만
    # 화폐단위 최대 100종, 각 화폐는 무한히 존재
    money.sort()

    dp = [0 for _ in range(n+1)] # dp[n] = n원 만드는 경우의수, dp[n] = dp[n-money[i]]
    dp[0] = 1 
    
    for m in money: # [1,2,5] 인데, 1원밖에 없는경우에다가 2원 추가, 에다가 5원 추가 이런식으로 dp 쌓을 것
        for goal in range(1, n+1):
            if goal - m >= 0:
                dp[goal] += dp[goal-m]
                dp[goal] %= MOD
    
    return dp[n] % MOD