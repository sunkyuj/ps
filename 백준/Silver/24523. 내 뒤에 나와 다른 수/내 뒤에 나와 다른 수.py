n = int(input())
a = list(map(int, input().split()))

cnt = 0
for i in range(n - 1):
    if a[i] != a[i + 1]:
        for j in range(cnt + 1):
            print(i + 2, end=" ")
        cnt = 0
    else:
        cnt += 1
for j in range(cnt+1):
    print(-1,end=" ")
