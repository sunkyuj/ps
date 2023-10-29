n = int(input())
scores = list(map(int, input().split()))
total = 0
average = 0

m = max(scores)

for i in range(n):
    total += scores[i] / m * 100

average = total / n
print(average)
