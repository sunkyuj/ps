import sys

input = lambda: sys.stdin.readline().rstrip()

n, m, k = map(int, input().split())
energy = [list(map(int, input().split())) for _ in range(n)]
tree_map = [[[] for _ in range(n)] for _ in range(n)]
energy_map = [[5 for _ in range(n)] for _ in range(n)]

in_range = lambda y, x: 0 <= y < n and 0 <= x < n

dy = [1, 0, -1, 0, 1, 1, -1, -1]
dx = [0, 1, 0, -1, 1, -1, 1, -1]

for _ in range(m):
    x, y, z = map(int, input().split())
    tree_map[x - 1][y - 1].append(z)


"""
봄: 나무가 나이만큼 양분 먹음, 나이 +1 (어린 나무부터)
여름: 봄에 죽은 나무 양분화, 양분 = 나무//2 
가을: 나이가 5의 배수면 인접8칸에 나이 1인 나무 생성
겨울: 양분 추가 (입력값)
"""


for _ in range(k):  # 1000
    rep = []
    # 봄

    for i in range(n):  # 10
        for j in range(n):  # 10
            trees = tree_map[j][i]
            die_i = -1
            die_e = 0

            for t in range(len(trees) - 1, -1, -1):  # ?
                if trees[t] <= energy_map[j][i]:
                    energy_map[j][i] -= trees[t]
                    trees[t] += 1
                    if trees[t] % 5 == 0:
                        rep.append((j, i))
                else:
                    # 여름
                    tree_map[j][i] = trees[t + 1 :]
                    energy_map[j][i] += sum([age // 2 for age in trees[: t + 1]])
                    break

    # 가을
    for x, y in rep:  # ?
        for dir in range(8):
            ny = y + dy[dir]
            nx = x + dx[dir]
            if in_range(ny, nx):
                tree_map[nx][ny].append(1)
    # 겨울
    for i in range(n):  # 10*10
        for j in range(n):
            energy_map[j][i] += energy[j][i]

ans = 0
# 나무 세기
for i in range(n):  # 10*10
    for j in range(n):
        ans += len(tree_map[j][i])

print(ans)
