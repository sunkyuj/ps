s, n, k, r1, r2, c1, c2 = map(int, input().split())
if s == 0:
    print("0")
    exit()

# 패턴은 N, K에 의해 결정
pattern = [["0" for _ in range(n)] for _ in range(n)]
start = (n - k) // 2
for i in range(start, start + k):
    for j in range(start, start + k):
        pattern[i][j] = "1"


ans = [["0" for _ in range(c2 - c1 + 1)] for _ in range(r2 - r1 + 1)]


def color(y, x):
    cur_size = n**s
    ysec, xsec = y, x
    for level in range(s, 0, -1):
        sec_size = cur_size // n
        ysec = y // sec_size
        xsec = x // sec_size
        if pattern[ysec][xsec] == "1":
            return "1"
        y -= sec_size * ysec
        x -= sec_size * xsec
        cur_size //= n

    return pattern[ysec][xsec]


for i in range(r1, r2 + 1):
    for j in range(c1, c2 + 1):
        ans[i - r1][j - c1] = color(i, j)

for r in ans:
    print("".join(r))