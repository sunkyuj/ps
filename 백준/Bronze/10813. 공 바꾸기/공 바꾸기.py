n, m = map(int, input().split())
b = []
temp = 0

for x in range(n):
    b.append(x + 1)

for y in range(m):
    i, j = map(int, input().split())
    temp = b[j - 1]
    b[j - 1] = b[i - 1]
    b[i - 1] = temp


for a in range(n):
    print(b[a], end=" ")
