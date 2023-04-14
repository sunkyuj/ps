def solution(m, n, puddles):
    a = [[0]*(m+1) for _ in range(n+1)]
    for i, j in puddles:
        a[j][i] = 1
    a[0][1] = 1
    for i in range(1, n+1):
        for j in range(1, m+1):
            if a[i][j]:
                a[i][j] = 0
            else:
                a[i][j] = (a[i-1][j]+a[i][j-1]) % 1_000_000_007
    return a[-1][-1]

# MOD = 1000000007
# def solution(m, n, puddles):
#     answer = 0
#     dp = [[0]*(m+1) for _ in range(n+1)]
#     for i in range(1,n+1):
#         if [i,1] in puddles:
#             break
#         dp[i][1] = 1
        
#     for j in range(1,m+1):
#         if [1,j] in puddles:
#             break
#         dp[1][j] = 1
    
#     for i in range(2,n+1):
#         for j in range(2,m+1):
#             if [i,j] in puddles:
#                 continue
#             dp[i][j] = dp[i-1][j] + dp[i][j-1]
            
#     for r in dp[1:]:
#         print(r[1:])
#     return dp[n][m]%MOD

"""
0 1 2 3
1 2 3 4
2 3 6 10

0 1 # 
1 2 2 2
2 # 2 4

1 1 1 1 1
1 2 # 1 2
1 3 # # 2
1 4 4 4 6


"""