def solution(routes):
    answer = 0
    routes.sort(key=lambda x: x[1])
    prev = -30001
    for route in routes:
        if route[0] > prev:
            answer+=1
            prev = route[1]
            
    
    return answer

# (-20    -15)
#     (-18         -13)
#             (-14         -5)
#                         (-5   -3)