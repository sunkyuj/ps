import sys

input = lambda: sys.stdin.readline().rstrip()

visit = [0] * 1000001
prime = []

for i in range(2, 1000001):
    if visit[i]:
        continue
    prime.append(i)
    for j in range(i * 2, 1000001, i):
        visit[j] = 1
pset = set(prime)

while 1:  # 10만
    n = int(input())  # 100만
    if n == 0:
        break

    flag = False
    for a in prime:
        if a < n and n - a in pset:
            print(f"{n} = {a} + {n-a}")
            flag = True
            break
    if not flag:
        print("Goldbach's conjecture is wrong.")
