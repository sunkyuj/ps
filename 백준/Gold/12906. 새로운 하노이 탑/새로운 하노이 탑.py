from collections import deque

hanoi = [[], [], []]
for i in range(3):
    inpt = input()
    if inpt[0] == "0":
        continue
    n, s = inpt.split()
    hanoi[i] = list(s)


def all_good(hanoi):
    for i in range(3):
        for x in hanoi[i]:
            if ord(x) != i + ord("A"):
                return 0
    return 1


def make_tup(hanoi):
    return ("".join(hanoi[0]), "".join(hanoi[1]), "".join(hanoi[2]))


q = deque()
visit = set()  # ("","","")
q.append((hanoi, 0))
visit.add(make_tup(hanoi))

while q:
    h, cnt = q.popleft()
    if all_good(h):
        print(cnt)
        exit()

    for i in range(3):
        for j in range(3):
            if i == j or h[i] == []:
                continue
            new = [h[0][:], h[1][:], h[2][:]]
            new[j].append(new[i].pop())
            new_tup = make_tup(new)
            if new_tup not in visit:
                q.append((new, cnt + 1))
                visit.add(new_tup)
