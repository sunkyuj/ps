n = int(input())
ans = 0


def is_gword(word):
    check = set()
    prev = ""
    for c in word:
        if c != prev:
            prev = c
            if c in check:
                return 0
            check.add(c)
    return 1


for _ in range(n):
    ans += is_gword(input())

print(ans)
