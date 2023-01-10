import sys

input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
    m = int(input())
    a = []
    while len(a) != m:
        a += list(map(int, input().split()))

    b = []
    cnt = 0
    ans_n = 0
    ans = ""
    for x in a:
        b.append(x)
        if len(b) % 2:  # odd
            cnt += 1
            b.sort()
            ans_n += 1
            ans += str(b[len(b) // 2]) + " "
            if cnt == 10:
                ans += "\n"
                cnt = 0
    print(ans_n)
    print(ans)
