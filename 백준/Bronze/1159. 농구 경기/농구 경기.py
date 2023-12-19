n = int(input())
alps = [0] * 26
for _ in range(n):
    c = input()[0]
    alps[ord(c) - ord("a")] += 1
ans = ""
for i in range(26):
    if alps[i] >= 5:
        ans += chr(i + 97)
if ans:
    print(ans)
else:
    print("PREDAJA")
