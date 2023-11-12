arr = [int(input()) for _ in range(9)]
arr.sort()
s = sum(arr)
 
for i in range(8):
    for j in range(i+1,9):
        if s-arr[i]-arr[j] == 100:
            for k in range(9):
                if k not in (i,j):
                    print(arr[k])
            exit()