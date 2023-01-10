import sys
import math

input = lambda: sys.stdin.readline().rstrip()


def init(idx, s, e):
    if s == e:
        if arr[s] == 0:
            seg[idx] = 0
        elif arr[s] > 0:
            seg[idx] = 1
        else:
            seg[idx] = -1

        return seg[idx]

    mid = (s + e) // 2
    seg[idx] = init(idx * 2, s, mid) * init(idx * 2 + 1, mid + 1, e)
    return seg[idx]


def change(idx, s, e):
    if s == e:
        if arr[s] == 0:
            seg[idx] = 0
        elif arr[s] > 0:
            seg[idx] = 1
        else:
            seg[idx] = -1

        return seg[idx]

    mid = (s + e) // 2
    if a <= mid:
        seg[idx] = change(idx * 2, s, mid) * seg[idx * 2 + 1]
    else:
        seg[idx] = seg[idx * 2] * change(idx * 2 + 1, mid + 1, e)

    return seg[idx]


def get(idx, s, e):
    if e < a or b < s:
        return 1

    if a <= s and e <= b:
        return seg[idx]

    mid = (s + e) // 2
    return get(idx * 2, s, mid) * get(idx * 2 + 1, mid + 1, e)


while 1:
    try:
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        h = math.ceil(math.log2(n)) + 1
        """
        4 - 7
        5 - 15
        7 - 15
        8 - 15
        9 - 31
        """
        seg = [0 for _ in range(1 << h)]
        init(1, 0, n - 1)

        ans = ""
        for _ in range(k):
            cmd, a, b = input().split()
            a = int(a)
            b = int(b)
            if cmd == "C":
                a -= 1
                arr[a] = b
                change(1, 0, n - 1)
            else:
                a -= 1
                b -= 1
                pmz = get(1, 0, n - 1)
                if pmz == 0:
                    ans += "0"
                elif pmz > 0:
                    ans += "+"
                else:
                    ans += "-"
        print(ans)
    except:
        break
