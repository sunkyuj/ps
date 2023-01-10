from queue import PriorityQueue

dy = [1, 0, -1, 0]
dx = [0, -1, 0, 1]

n = int(input())
board = [input() for _ in range(n)]

visit = [[0 for _ in range(n)] for _ in range(n)]
visit[0][0] = 1

pq, bq = PriorityQueue(), PriorityQueue()
pq.put((0, 0, 0))  # cost,y,x

while 1:
    while not pq.empty():
        cost, y, x = pq.get()
        if (y, x) == (n - 1, n - 1):
            print(cost)
            exit()

        for k in range(4):
            ny, nx = y + dy[k], x + dx[k]
            if 0 <= ny < n and 0 <= nx < n and not visit[ny][nx]:
                if board[ny][nx] == "1":  # white
                    pq.put((cost, ny, nx))
                else:  # black
                    pq.put((cost + 1, ny, nx))
                visit[ny][nx] = 1
