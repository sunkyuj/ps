n = int(input())  # 1억

l = len(str(n))
ans = l * (n - 10 ** (l - 1) + 1)

for i in range(l - 1, 0, -1):
    ans += i * 9 * (10 ** (i - 1))
print(ans)
