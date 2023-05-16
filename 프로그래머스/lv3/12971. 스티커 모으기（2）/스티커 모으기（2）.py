def solution(sticker):
    if len(sticker)<=3:
        return max(sticker)
    
    dp1=[0]*(len(sticker))
    dp1[0]=sticker[0]
    dp1[1]=sticker[0]
    for i in range(2,len(sticker)-1):
        dp1[i] = max(dp1[i-2]+sticker[i],dp1[i-1])
        
    # print(dp1)
    
    dp2=[0]*(len(sticker))
    dp2[1]=sticker[1]
    dp2[2] = sticker[1]
    
    for i in range(3,len(sticker)):
        dp2[i] = max(dp2[i-2]+sticker[i],dp2[i-1])
        
    # print(dp2)
    
    dp3=[0]*(len(sticker))
    dp3[2] = sticker[2]
    
    for i in range(3,len(sticker)):
        dp3[i] = max(dp3[i-2]+sticker[i],dp3[i-1])
        
    # print(dp3)
    
    
    return max(max(dp1),max(dp2),max(dp3))
    
 