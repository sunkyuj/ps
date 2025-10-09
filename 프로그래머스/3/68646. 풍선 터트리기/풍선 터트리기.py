# 1:50

def solution(a):
    answer = 0
    # 두개 중 큰거 터친다(작은거 딱한번 가능), 붙인다 하나 남을때까지 반복

    # a 100만, 각 수는 +-10억, 모두 다름
    
    asort = sorted(a)
    n = len(a)
    left_under = [0]*n
    right_under = [0]*n
    
    
    # 오른쪽 한번 갈거
    left_min_idx = 0
    for i in range(1, n):
        if a[i] > a[left_min_idx]: # 지금 놈이 왼쪽 최소보다 크면
            left_under[i] += 1 # 지금 놈의 left under 늘림
        else:
            right_under[left_min_idx] += 1
            left_min_idx = i    
    
    # 왼쪽 한번 갈거
    right_min_idx = n-1
    for i in range(n-2, -1, -1):
        if a[i] > a[right_min_idx]: 
            right_under[i] += 1
        else:
            left_under[right_min_idx] += 1
            right_min_idx = i

    total = [ left_under[i] != 1 or right_under[i] != 1 for i in range(n)]

    # 최후에 남기는게 가능한 풍선 개수
    return sum(total)

"""
[9 -1 -5]

(9, -1)
: 9펑 -> [-1 -5]
: -1펑 (작펑) -> [9 -5]

(-1, -5)
: -1펑 -> [9 -5]
: -5펑 (작펑) -> [9 -1]
"""


"""
인접하다
큰거 터친다 (딱한번 작은거)

9 (o) -1 (o) -5 (o)

9 -1 



"""