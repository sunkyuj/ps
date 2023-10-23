import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())  # 30만
if n == 0:
    print(0)
    exit()
arr = [int(input()) for _ in range(n)]
arr.sort()
rem = int(n * 0.15 + 0.5)
m = n - rem * 2
print(int(sum(arr[rem : n - rem]) / m + 0.5))
