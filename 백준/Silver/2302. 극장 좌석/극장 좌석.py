n = int(input())
m = int(input())
seat = [0] * n
for _ in range(m):
    vip = int(input())
    seat[vip - 1] = 1
s = "".join(list(map(str, seat))).split("1")

fib = [1, 1]
for i in range(2, 41):
    fib.append(fib[i - 1] + fib[i - 2])

ans = 1
for cont in s:
    l = len(cont)
    ans *= fib[l]
print(ans)
