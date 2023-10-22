from heapq import heappop, heappush


n = int(input())
bs = [0] * (n + 1)
hq = []  # (end,idx)
indegree = [0] * (n + 1)
after = [set() for _ in range(n + 1)]
fin = [0] * (n + 1)
visit = [0] * (n + 1)


for i in range(1, n + 1):
    info = list(map(int, input().split()))
    cost = info[0]
    need = info[1:-1]
    bs[i] = [cost, need]

    if len(need) == 0:
        heappush(hq, (cost, i))

    indegree[i] = len(need)
    for x in need:
        after[x].add(i)

while hq:
    end, idx = heappop(hq)
    if visit[idx]:
        continue

    fin[idx] = end
    visit[idx] = 1

    for x in after[idx]:
        indegree[x] -= 1
        if indegree[x] == 0:
            heappush(hq, (end + bs[x][0], x))


for i in range(1, n + 1):
    print(fin[i])
