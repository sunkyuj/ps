n = int(input())
rel = input().split()

min_val, max_val = "9999999999", "0"
visit = [0] * 10


def f(snum):
    if len(snum) == n + 1:
        global min_val, max_val
        min_val = min(min_val, snum)
        max_val = max(max_val, snum)
        return

    cur_num = int(snum[-1])
    visit[cur_num] = 1
    idx = len(snum) - 1
    bigsmall = rel[idx]

    if bigsmall == "<":
        for i in range(cur_num + 1, 10):
            if visit[i]:
                continue
            f(snum + str(i))
    else:
        for i in range(cur_num):
            if visit[i]:
                continue
            f(snum + str(i))

    visit[cur_num] = 0


for i in range(10):
    f(str(i))

print(max_val)
print(min_val)
