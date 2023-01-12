from queue import PriorityQueue
d = [(1,0),(0,1),(-1,0),(0,-1)]

def too_close(place,i,j):
    
    pq = PriorityQueue()
    visit = set()
    
    pq.put((0,i,j))
    visit.add((i,j))
    while not pq.empty():
        dist,y,x = pq.get()
        if place[y][x] == "P" and 1<=dist<=2:
            return 1
        if dist==2:
            continue
        
        for dy,dx in d:
            ny,nx = y+dy, x+dx
            if 0<=ny<5 and 0<=nx<5 and place[ny][nx] != "X" and (ny,nx) not in visit:
                pq.put((dist+1,ny,nx))
                visit.add((ny,nx))

    return 0
    
def f(place):
    for i in range(5):
        for j in range(5):
            if place[i][j] == "P" and too_close(place,i,j):
                return 0
    return 1



def solution(places):
    answer = []
    for place in places:
        answer.append(f(place))
    return answer