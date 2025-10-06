"""
a b c ... z -> 26

aa ab ac ... az -> 26
ba bb bc ... bz -> 26
...
za zb zc ... zz -> 26


n자리수 주문 총 개수 -> 26**n

a : 1*26**0
aa : 1*26**1 +1*26**0
abc : 1*26**2 +2*26**1 + 3*26**0

"""
    
def solution(n, bans):
    # n 1000조, bans는 30만
    
    answer = ''
    alp_ord = { alp: i+1 for i,alp in enumerate("abcdefghijklmnopqrstuvwxyz")}
    
    ban_nums = []
    for ban in bans:
        l = len(ban)
        num = 0
        for i in range(l):
            c = ban[i]
            ex = l-1-i
            num += alp_ord[c] * 26**ex
        ban_nums.append(num)
            
    ban_nums.sort()
    
    real = n
    for num in ban_nums:
        if real >= num:
            real+=1
        else:
            break

    a,b = real,0
    while a:
        a,b = a//26, a%26
        if b == 0:
            b = 26
            a -= 1
        answer += chr(b+96)

    return answer[::-1]