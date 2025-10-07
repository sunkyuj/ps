def check(val, rocks, n, dist):
    # 각 바위 사이 거리 구하는데, val 보다 작으면 돌 치우고 n-=1, n 남으면 성공
    prev = 0
    end = dist
    removed = set()
    for rock in rocks:
        diff = rock - prev
        if diff < val: # 돌 삭제
            n -= 1
            removed.add(rock)
        else: # pass
            prev = rock
            
            
    # 만약 막돌 치웠는데도 작으면
    if end-prev < val:
        for i in range(len(rocks)-1,-1,-1):
            rock = rocks[i]
            if rock in removed:
                continue
            
            if end - rock < val:
                n -= 1
            else: 
                break
                
    return n >= 0

def get_min_dist(rocks, dist):
    mdist = dist
    prev = 0
    for rock in rocks:
        mdist = min(mdist, rock - prev)
        prev = rock
    
    mdist = min(mdist, dist-rocks[-1])
    return mdist


def solution(distance, rocks, n): # rocks 5만
    # 돌 사이 거리 최솟값이 제일 커야함!
    
    # l,r이 답을 포함할 수 있어야함
    # TTTTFFFF
    
    rocks.sort()
    l,r = get_min_dist(rocks, distance)-1, distance+1
    
    while l+1 < r:
        mid = (l+r)//2
        # print(l,mid,r)
        if check(mid, rocks, n, distance):
            l = mid
        else:
            r = mid
    
    return l

""" 11 12 6 7 8

  0                 1                   2
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 
*   =                 =     =     =       =       *
  2         9            3     3      4       4
"""