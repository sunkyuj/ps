def f(i,s):
    global answer,nums,tar
    
    if i == len(nums):
        if s == tar:
            answer+=1
        return
    
    f(i+1,s+nums[i])
    f(i+1,s-nums[i])
    
    
        
    
def solution(numbers, target):
    
    global answer, nums, tar
    answer = 0
    nums = numbers
    tar = target
    
    f(0,0)
    
    
    return answer