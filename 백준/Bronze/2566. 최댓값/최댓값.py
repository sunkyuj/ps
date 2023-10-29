n = []
max = -1
a, b = 0, 0

for i in range(9):
    li = list(map(int, input().split()))
    n.append(li)

for i in range(9):
    for j in range(9):
        if max < n[i][j]:
            max = n[i][j]
            a = i + 1
            b = j + 1

print(max)
print(a, b)
