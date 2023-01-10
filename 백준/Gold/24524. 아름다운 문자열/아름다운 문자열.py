s = input()
t = input()

cnt = 0
l = [0 for _ in t]  # l[k] = t[k]까지 있는 것의 개수
t_set = set(t)


for x in s:
    if x in t_set:
        if x == t[0]:
            l[0] += 1
        else:
            idx = t.find(x)  # t[idx] == x
            if l[idx - 1]:
                l[idx - 1] -= 1
                l[idx] += 1


print(l[-1])
