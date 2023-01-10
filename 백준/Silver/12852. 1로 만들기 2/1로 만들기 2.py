n=int(input())
MAX = 100001

from queue import Queue
from queue import PriorityQueue

pq = PriorityQueue() # cost, x //파이썬에서는 오름차순(123)으로 정렬
dist = [MAX for i in range(n+1)]
edge = [[] for i in range(n+1)]

for i in range(2,n+1):
    if(i%3==0):
        edge[i].append(i//3)
    if(i%2==0):
        edge[i].append(i//2)
        
    edge[i].append(i-1)

pq.put((0,n,[n]))
while(not pq.empty()):
    front = pq.get()
    cost = front[0]
    x = front[1]
    path = front[2]

    if(x==1):
        print(cost)
        for p in path:
            print(p,end=' ')
        exit()

    if(dist[x]<cost): continue

    for nxt in edge[x]:
        if(dist[nxt]>cost+1):
            dist[nxt]=cost+1
            pq.put((dist[nxt],nxt,path+[nxt]))









