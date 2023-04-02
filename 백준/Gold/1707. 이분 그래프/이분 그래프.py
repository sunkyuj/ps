from collections import deque
import sys

input = lambda: sys.stdin.readline().rstrip()


def bfs(start):

    q.append(start)  # start node : 1
    visit[start] = 1  # start color : 1

    while q:
        cur = q.popleft()

        for to in conn[cur]:
            if visit[cur] == visit[to]:  # 인접 색이 같은 색이면 땡
                return 0
            if not visit[to]:
                q.append(to)
                visit[to] = visit[cur] * -1  # 다음 목적지는 현재 색이랑 다른 색으로

    return 1


k = int(input())

for tc in range(k):
    q = deque()
    v, e = map(int, input().split())
    conn = {i: set() for i in range(1, v + 1)}
    visit = [0] * (v + 1)
    for _ in range(e):
        a, b = map(int, input().split())
        conn[a].add(b)
        conn[b].add(a)

    check = True
    # 그래프가 여러개로 쪼개진 경우
    for i in range(1, v + 1):
        if not visit[i]:
            check &= bfs(i)

    print("YES") if check else print("NO")

    """

    1-3-4-2-5-6
    \________/
    """
