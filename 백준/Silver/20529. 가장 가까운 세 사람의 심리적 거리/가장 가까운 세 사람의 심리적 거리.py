from collections import Counter


def f(picked):
    global ans
    if len(picked) == 3:
        l = 0
        for i in range(3):
            m1, m2 = picked[i], picked[(i + 1) % 3]
            l += sum([int(m1[j] != m2[j]) for j in range(4)])
        ans = min(ans, l)
        return

    for m in c_dict:
        if c_dict[m]:
            c_dict[m] -= 1
            f(picked + [m])
            c_dict[m] += 1
    return


for _ in range(int(input())):
    n = int(input())
    mbti = list(input().split())
    counter = Counter(mbti)  # 10만
    c_list = list(counter)
    c_dict = dict(counter)
    ans = 999
    f([])
    print(ans)
