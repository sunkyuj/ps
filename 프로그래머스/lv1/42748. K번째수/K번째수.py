def solution(array, commands):
    answer = []
    for command in commands:
        a,b,c = command
        li = array[a-1:b]
        li.sort()
        answer.append(li[c-1])
    return answer