import sys
import heapq

input = lambda: sys.stdin.readline().rstrip()
tc = 1
MAX = 9999999

while 1:
    n = int(input())
    if n == 0:
        break
    board = [list(map(int, input().split())) for _ in range(n)]
    dist = [[MAX] * n for _ in range(n)]
    dist[0][0] = board[0][0]
    hq = []
    heapq.heappush(hq, (dist[0][0], 0, 0))  # cost, y, x
    while hq:
        cost, y, x = heapq.heappop(hq)
        if dist[y][x] < cost:
            continue
        for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            ny, nx = y + dy, x + dx
            if 0 <= ny < n and 0 <= nx < n and dist[ny][nx] > dist[y][x] + board[ny][nx]:
                dist[ny][nx] = dist[y][x] + board[ny][nx]
                heapq.heappush(hq, (dist[ny][nx], ny, nx))

    ans = dist[n - 1][n - 1]
    print(f"Problem {tc}: {ans}")
    tc += 1
