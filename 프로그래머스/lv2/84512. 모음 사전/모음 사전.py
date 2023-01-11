def solution(word):
    answer = 0
    aeiou = ["","A","E","I","O","U"]
    dic = []
    for i1 in aeiou:
        for i2 in aeiou:
            for i3 in aeiou:
                for i4 in aeiou:
                    for i5 in aeiou:
                        dic.append(i1+i2+i3+i4+i5)
    dic = list(set(dic))
    dic.sort()
    
    return dic.index(word)
