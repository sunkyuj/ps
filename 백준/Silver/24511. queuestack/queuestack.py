import sys
from collections import deque

# sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m

n = int(input())
order = input().split()  # 0 q, 1 s
init = list(map(int, input().split()))
q = deque()
for i in range(n):
    if order[i] == "0":
        q.append(init[i])
m = int(input())
put = list(map(int, input().split()))
for x in put:
    q.appendleft(x)
    print(q.pop(), end=" ")
