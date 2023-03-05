def solution(s):
    answer = [0,0]
    
    bins, zeros = 0,0
    while s != "1":
        z = s.count("0")
        s = "1"*(len(s)-z)
        zeros += z
        s = bin(len(s))[2:]
        bins+=1
    answer[0], answer[1] = bins,zeros
    return answer