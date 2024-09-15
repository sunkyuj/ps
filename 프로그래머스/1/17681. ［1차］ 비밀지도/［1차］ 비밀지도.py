def solution(n, arr1, arr2):
    answer = []
    
    for i in range(n):
        x = arr1[i]
        y = arr2[i]
        
        bx = bin(x)[2:]
        bx = "0"*(n-len(bx))+bx
        by = bin(y)[2:]
        by = "0"*(n-len(by))+by
        
        row = ""
        for j in range(n):
            row += " " if (bx[j],by[j]) == ("0","0") else "#"
        answer.append(row)
    return answer