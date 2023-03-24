n = int(input())
arr = list(map(int, input().split()))
b, c = map(int, input().split())
ans = 0
for a in arr:
    a -= b
    ans += 1
    if a <= 0:
        continue
    ans += a // c + (1 if a % c else 0)
print(ans)
