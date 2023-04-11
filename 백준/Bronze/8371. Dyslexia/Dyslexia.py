n = int(input())
s = input()
rewritten = input()
ans = 0
for i in range(n):
    if s[i] != rewritten[i]:
        ans += 1
print(ans)
