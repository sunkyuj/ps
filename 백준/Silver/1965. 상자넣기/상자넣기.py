n = int(input())
arr = list(map(int, input().split()))
lis = [1] * n
for i in range(n):
    for j in range(i):
        if arr[i] > arr[j]:
            lis[i] = max(lis[i], lis[j] + 1)
print(max(lis))
