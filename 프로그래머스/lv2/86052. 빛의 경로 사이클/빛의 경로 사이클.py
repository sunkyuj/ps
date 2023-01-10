# u r d l
d = [(-1, 0), (0, 1), (1, 0), (0, -1)]


def cycle(start_i, start_j, start_k):
    global g, r, c, visit
    i, j, k = start_i, start_j, start_k
    l = 0

    while True:
        l += 1
        visit[i][j][k] = 1

        i = (i + d[k][0]) % r
        j = (j + d[k][1]) % c

        if g[i][j] == "L":
            k = (k - 1) % 4
        elif g[i][j] == "R":
            k = (k + 1) % 4

        if (i, j, k) == (start_i, start_j, start_k):
            break

    return l


def solution(grid):
    answer = []
    global g, r, c, visit
    g = grid
    r, c = len(grid), len(grid[0])
    visit = [[[0, 0, 0, 0] for _ in range(c)] for _ in range(r)]
    for i in range(r):
        for j in range(c):
            for k in range(4):
                if visit[i][j][k]:
                    continue
                answer.append(cycle(i, j, k))
                print()
    answer.sort()
    return answer
