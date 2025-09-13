import sys

input = lambda: sys.stdin.readline().rstrip()

NONE = 0
P1 = 1
P2_0 = 2  # 100+
P2_1 = 3  # 1+

# (100+1+ | 01)+


def p2_0_iter(i, s):
    i += 2
    while s[i] == "0":
        i += 1
        if i >= len(s):
            return -1
    # 이젠 s[i] == 1
    i += 1
    return i


def solve(s):
    status = NONE
    i = 0
    l = len(s)

    while i < l:
        if status == NONE and s[i] == "0":
            if i + 1 < l and s[i + 1] == "1":
                i += 2
                continue
            return 0

        if status == NONE and s[i] == "1":
            if i + 2 < l and s[i + 1] == "0" and s[i + 2] == "0":
                i = p2_0_iter(i, s)
                if i == -1:
                    return 0
                status = P2_1
                continue
            return 0

        if status == P2_1:
            if s[i] == "0":
                status = NONE
                continue
            if i + 2 < l and s[i + 1] == "0" and s[i + 2] == "0":
                i = p2_0_iter(i, s)
                if i == -1:
                    return 0
                status = P2_1
                continue
            i += 1
            continue

    if status == P2_0:
        return 0
    return 1


for _ in range(int(input())):
    ans = solve(input())
    print("YES" if ans else "NO")
