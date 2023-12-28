from collections import deque
import sys

input = lambda: sys.stdin.readline().rstrip()

primes = set(range(1001, 10000, 2))  # 1000 ~ 9999
for i in range(3, 10000):
    for j in range(i + i, 10000, i):
        if j in primes:
            primes.remove(j)
primes = sorted(list(primes))


def bfs(start, goal):
    q = deque()
    visit = set()
    q.append((start, 0))
    visit.add(start)
    while q:
        cur, l = q.popleft()
        if cur == goal:
            return l

        snum = str(cur)
        for i in range(4):
            for digit in range(10):
                new = snum[:i] + str(digit) + snum[i + 1 :]
                num = int(new)
                if num in primes and num not in visit:
                    q.append((num, l + 1))
                    visit.add(num)

    return -1


for _ in range(int(input())):
    start, goal = map(int, input().split())
    ans = bfs(start, goal)
    if ans == -1:
        print("Impossible")
    else:
        print(ans)
