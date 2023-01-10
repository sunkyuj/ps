import sys

sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m


c = int(input())
ans = 0
for _ in range(c):
    s = input()
    l = len(s)
    i = 0
    cnt = 0
    while i < l:
        if s[i] == "f":
            sub = s[i : i + 3]
            if sub == "for":
                cnt += 1
                i += 2
        if s[i] == "w":
            sub = s[i : i + 5]
            if sub == "while":
                cnt += 1
                i += 4
        i += 1
    ans = max(ans,cnt)
print(ans)