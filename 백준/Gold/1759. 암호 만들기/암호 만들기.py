l, c = map(int, input().split())  # 최소 1개 모음, 최소 두개 자음
arr = input().split()
arr.sort()

ans = []
aeiou = "aeiou"


def f(idx, s):
    if len(s) == l:
        # 검사
        ja, mo = 0, 0
        for x in s:
            if x in aeiou:
                mo += 1
            else:
                ja += 1
        if ja >= 2 and mo:
            ans.append(s)
        return

    if idx == c:
        return

    f(idx + 1, s + arr[idx])  # pick idx
    f(idx + 1, s)  # no


"""
a c i s t w

"""
f(0, "")

ans.sort()
for x in ans:
    print(x)
