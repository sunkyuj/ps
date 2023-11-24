from collections import defaultdict

n = int(input())
ans = 0
letters = []
alps = defaultdict(int)
for _ in range(n):
    s = input()
    letters.append(s)
    i = 0
    for c in s[::-1]:
        alps[c] += 10**i
        i += 1
nums = [s for s in alps.values()]
nums.sort(reverse=1)

i = 9
for num in nums:
    ans += num * i
    i -= 1
print(ans)
